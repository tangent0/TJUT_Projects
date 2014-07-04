set define on
set verify off
prompt Input the part number and how many parts to delete:
accept part_num number prompt 'part number: '
accept out_num  number prompt 'the delete number: '

update ora00176.part
set qty_stock = qty_stock - &out_num
where part_number = &part_num;
