set define on
set verify off

prompt Input the data of the new product:
accept product_number      number prompt 'product_number: '
accept supplier_number     number prompt 'supplier_number: '
accept product_name        char   prompt 'product_name: '
accept product_unit        number   prompt 'product_unit: '
accept supplier_unit_price number prompt 'supplier unit price: '

insert into ora00176.product
values(&product_number, &supplier_number, '&product_name', '&product_unit', &supplier_unit_price);
