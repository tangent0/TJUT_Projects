set define on
set verify off

prompt Input data of the new Purchase_order:
accept po_number      prompt 'PO_number: '
accept po_date        prompt 'date: '
accept emp_num        prompt 'PA_number: '
accept supplier_id    prompt 'supplier_id: '
accept product_number prompt 'product_number: '
accept qty            prompt 'quantity: '

insert into ora00176.purchase_order
values(&po_number, &po_date, 
       &qty*
       (select supplier_unit_price 
        from product
	    where product_number = &product_number
          and supplier_number = &supplier_id
	)
       ,'not_completed');

insert into ora00176.detail
values(&po_number, &product_number, &qty, 0);

insert into ora00176.business
values(&po_number, &supplier_id);

insert into ora00176.task
values(&po_number, &emp_num);
