set define on
set verify off
prompt Input the data of the new supplier:
accept supplier_id   number prompt 'supplier_number: '
accept supplier_name char   prompt 'supplier_name: '
accept addr          char   prompt 'supplier_address: '
accept contact       char   prompt 'supplier_contact_name: '

insert into ora00176.supplier
values(&supplier_id, '&supplier_name', '&addr' , '&contact');
