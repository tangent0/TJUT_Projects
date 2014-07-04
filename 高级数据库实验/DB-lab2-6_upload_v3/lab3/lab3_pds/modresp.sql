set define on
set verify off
prompt Input the part number and the component number:
accept part_number number prompt 'part_number: '
accept emp_old     number prompt 'old PA_number: '
accept emp_new     number prompt 'new PA_number: '

update ora00176.responsible
set emp_num = &emp_new
where part_number = &part_number and emp_num = &emp_old;
