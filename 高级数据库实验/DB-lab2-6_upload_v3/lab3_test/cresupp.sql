--Request to create a new supplier
set define on
set verify off

prompt Creation of a new supplier
prompt
accept num number prompt 'Enter the supplier id:'
accept name char prompt 'Enter the name of the supplier:'
accept adr char prompt 'Enter then address of the supplier:'
accept rep char prompt 'Enter the contact name:'

insert into supplier(supplier_id, supplier_name, addr, contact)
values(&num, '&name', '&adr', '&rep');
