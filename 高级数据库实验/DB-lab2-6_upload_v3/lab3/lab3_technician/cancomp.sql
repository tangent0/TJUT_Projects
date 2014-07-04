set define on
set verify off
prompt Input the part number and the component number:
accept part_num number prompt 'part_number: '
accept comp_num number prompt 'component_number: '

delete from component
where part_number = &part_num
  and part_number_component = &comp_num;
