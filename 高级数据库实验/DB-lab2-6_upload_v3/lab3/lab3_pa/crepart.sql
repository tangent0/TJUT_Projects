set define on
set verify off
prompt Input the data of a new part:
accept part_number number prompt 'part_number: '
accept part_name   char   prompt 'part_name: '
accept qty_stock   number prompt 'qty_stock: '
accept qty_minimum number prompt 'qty_minimum: '
accept qty_ordered number prompt 'qty_ordered: '
accept unit        char   prompt 'unit: '
accept unit_price  number prompt 'unit_price: '

insert into ora00176.part
values(&part_number, '&part_name', &qty_stock, &qty_minimum, &qty_ordered, '&unit', &unit_price); 