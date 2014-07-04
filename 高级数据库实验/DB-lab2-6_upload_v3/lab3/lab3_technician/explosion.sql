set define on
set verify off
prompt Input a part number:
accept num prompt 'number: '

select part.part_number, part.part_name "component"
from part, component
where part.part_number = component.part_number_component
  and component.part_number = &num;