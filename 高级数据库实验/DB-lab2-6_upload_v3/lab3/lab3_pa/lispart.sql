--Example of reformatting and input variable
set define on
set verify off

prompt Enter a part number please: 
accept num number prompt 'number: '
column unit_price format $99,999.99 heading 'UNIT_PRICE'
column part_name  heading 'PART_NAME'

--execution of request sql
select * from ora00176.part
where part_number = &num;