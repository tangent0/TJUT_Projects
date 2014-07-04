set define on
set verify off
prompt Input the number of the Purchase Agent:
accept num number prompt 'number: '

select count(*), sum(total) from ora00176.purchase_order, ora00176.task
 where purchase_order.po_number = task.po_number
   and emp_num = &num;