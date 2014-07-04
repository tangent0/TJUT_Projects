--drop table employee;
--drop table department;

create table department
( name_dept char(10) primary key,
  no_dept   number(2) unique,
  tel_dept  char(8) default '545-5011',
  budget    number(7) default 20000);

create table employee
(emp_number number(5) primary key,
 name_emp   char(15) not null,
 addr       char(25) default 'Saguenay',
 commission number(10),
 salary     number(5) default 0,
 dept_name  char(10) references department(name_dept)
);
