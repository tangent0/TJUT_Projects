set define on
set verify off
prompt Input a part_number:
accept num prompt 'number: '

select * from part
where part_number = &num;