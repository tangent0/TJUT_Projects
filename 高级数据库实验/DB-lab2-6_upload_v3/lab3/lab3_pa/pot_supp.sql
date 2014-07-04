set define on
set verify off
prompt Input a part number:
accept num number prompt 'part_number: '

select product.supplier_number, product.product_number,
       product.product_unit, product.supplier_unit_price
from ora00176.product, ora00176.potential
where product.product_number = potential.product_number
  and product.supplier_number = potential.supplier_id
  and part_number = &num;