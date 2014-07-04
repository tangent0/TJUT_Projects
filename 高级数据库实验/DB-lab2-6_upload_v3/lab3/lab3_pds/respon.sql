set define on
set verify off
prompt Input the name of the Purchase Agent:
accept num number prompt 'PA_number: '

select pa_agent.emp_num, pa_agent.pa_name, part.part_number, part.part_name
from ora00176.responsible, ora00176.part, ora00176.pa_agent
where part.part_number = responsible.part_number
  and pa_agent.emp_num = responsible.emp_num
  and pa_agent.emp_num = &num;
