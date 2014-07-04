set define on
set verify off
prompt Input a component number:
accept num prompt number:

select part.part_number, part_name
from part, component
where part.part_number = component.part_number
  and component.part_number_component = &num;