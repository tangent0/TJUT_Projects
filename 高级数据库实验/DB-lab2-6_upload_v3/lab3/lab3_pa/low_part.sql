set define on
set verify off
prompt Input a PA number:
accept num number prompt 'PA number: '

select part.part_number, part_name
from ora00176.part, ora00176.responsible
where part.part_number=responsible.part_number
  and emp_num=&num 
  and qty_stock + qty_ordered <= qty_minimum;