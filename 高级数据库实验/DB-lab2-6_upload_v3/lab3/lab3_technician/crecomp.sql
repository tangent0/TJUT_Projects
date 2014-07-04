set define on
set verify off

prompt Input the data of a new part:
accept part_number number prompt 'part_number: '
accept comp_number number prompt 'component_number: '

insert into ora00176.component
values(&part_number, &comp_number);
