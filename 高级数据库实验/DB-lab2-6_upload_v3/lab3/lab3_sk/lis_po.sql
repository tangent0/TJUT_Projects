set define on
set verify off
prompt Input the Purchase Order number:
accept num number prompt 'number: '

select purchase_order.po_number, purchase_order.po_date,
       pa_agent.pa_name,
	   business.supplier_id,
       supplier.supplier_name, supplier.addr, supplier.contact
from 
     ora00176.purchase_order,
	 ora00176.task,
     ora00176.business,
     ora00176.pa_agent, ora00176.supplier, ora00176.detail
where 
     purchase_order.po_number = detail.po_number
 and purchase_order.po_number = task.po_number
 and purchase_order.po_number = business.po_number
 and task.emp_num = pa_agent.emp_num
 and business.supplier_id = supplier.supplier_id
 and purchase_order.po_number = &num;


select detail.product_number, product_name, product_unit, 
        supplier_unit_price, qty_ordered, qty_received
from 
     ora00176.detail, ora00176.product, ora00176.business
where 
      detail.product_number = product.product_number
  and business.po_number = detail.po_number
  and detail.po_number = &num
  and product.supplier_number = business.supplier_id;
