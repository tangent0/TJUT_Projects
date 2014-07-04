set define on
set verify off
prompt Input the number and name of the new Purchase Agent:
accept num  number prompt 'number: '
accept name char   prompt 'name: '

insert into ora00176.pa_agent values(&num,'&name');
