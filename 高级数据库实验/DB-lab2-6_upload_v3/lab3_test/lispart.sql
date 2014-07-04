--Example of reformatting and input variable
set define on
set verify off
prompt Enter a part number please
accept num number prompt 'number:'
column unit_price format $99,999.99 heading 'price'
column part_name heading 'Name of part'

--execution of sql
select part_number "Number", part_name, qty_stock "quant in stock", unit_price
from part where part_number=&num;
