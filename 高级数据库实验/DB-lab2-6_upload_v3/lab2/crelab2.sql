-- Incomplete example of table creation for TUT-Lab2 8trd157
-- Paul Girard Ph.D. UQAC
--
-- modified by ora00176 in may,2013

--drop tables
drop table potential;
drop table business;
drop table task;

drop table responsible;

drop table detail;

drop table product;
drop table component;
drop table part;

drop table pa_agent;
drop table purchase_order;
drop table supplier;

--drop views
drop view purchase_pds;
drop view sks;


--pa_agent, purchase_order, supplier
create table pa_agent
        (emp_num        number(4)      	primary key,
        pa_name    	    char(15)    not null);
create table purchase_order
        (po_number     	number(4)	primary key,
        po_date         char(8)         not null,
        total           number(6,2)     default 0,
        status          char(15)        default 'not_completed');
create table supplier
        (supplier_id    number(4)       primary key,
        supplier_name 	char(15)        not null,
        addr        	char(20)        not null,
        contact         char(15)        not null);
		
--part and component
create table part
(part_number number(4)   primary key,
 part_name   char(15)    not null,
 qty_stock   number(6)   default 0,
 qty_minimum number(6)   default 0,
 qty_ordered number(6)   default 0,
 unit        char(15)    not null,
 unit_price  number(5,2) default 0
);

create table component
(part_number           number(4) not null references part(part_number),
 part_number_component number(4) not null references part(part_number),
 constraint pk_component primary key(part_number,part_number_component)
);

--product
create table product
(product_number      number(4)   unique,
 supplier_number     number(5)   not null references supplier(supplier_id),
 product_name        char(15)	 not null,
 product_unit        number(4)   not null,
 supplier_unit_price number(4,2) default 0,
 constraint pk_product primary key(supplier_number,product_number)
);

--detail
create table detail
(po_number       number(4) not null,
 product_number  number(4) not null,
 qty_ordered     number(4) not null,
 qty_received    number(4) not null,
 constraint con_det_or check(qty_ordered>=qty_received), 
 constraint pk_detail primary key(po_number,product_number)  
);

--responsible
create table responsible
(emp_num     number(5) not null references pa_agent(emp_num),
 part_number number(5) not null references part(part_number),
 constraint pk_responsible primary key(emp_num, part_number)
);

--task, business, potential
create table task
(po_number number(5) not null references purchase_order(po_number),
 emp_num   number(5) not null references pa_agent(emp_num),
 constraint pk_task primary key(po_number, emp_num)
);

create table business
(po_number   number(5) not null references purchase_order(po_number),
 supplier_id number(5) not null references supplier(supplier_id),
 constraint pk_business primary key(po_number, supplier_id)
);

create table potential
(part_number    number(5) not null references part(part_number),
 supplier_id    number(5) not null references supplier(supplier_id),
 product_number number(5) not null references product(product_number),
 constraint pk_potential primary key(part_number,supplier_id,product_number)
);

--view for purchase_pds
create or replace view purchase_pds as
	select po_number,total from purchase_order;       

--view for sks
create or replace view sks as
  select part_number,qty_stock,unit,unit_price from part;
