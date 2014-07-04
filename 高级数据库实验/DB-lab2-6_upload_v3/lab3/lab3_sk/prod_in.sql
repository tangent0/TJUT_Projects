set define on
set verify off
prompt Input the Purchase Order number, product number and the quantity of product:
accept po_num number prompt 'PO_number: '
accept product_num   prompt 'product_number: '
accept qty           prompt 'quantity: '

update ora00176.detail
set qty_received = qty_received + &qty
where po_number = &po_num
  and product_number = &product_num;

update ora00176.part
set qty_stock = qty_stock + &qty,
    qty_ordered = qty_ordered - &qty
where part_number in 
      (select part_number
       from ora00176.potential, ora00176.business
       where potential.supplier_id = business.supplier_id
         and business.supplier_id = potential.supplier_id
	     and product_number = &product_num
      );
