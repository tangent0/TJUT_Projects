drop table part2;
create table part2
 	(part_number	number(5) primary key,
	part_name	char(15),
	status		char(1) default 'A');
