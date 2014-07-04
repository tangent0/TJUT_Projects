<?php
	$creat_table_sql_array = array(
	"
	CREATE TABLE Admin 
	(
		Admin_id   int NOT NULL auto_increment PRIMARY KEY,
		Admin_name varchar(20) NOT NULL,
		Admin_pwd  varchar(20) NOT NULL
	)
	"
	,
	"
	CREATE TABLE Reader 
	(
		Reader_id   int NOT NULL auto_increment PRIMARY KEY,
		Reader_name varchar(20) NOT NULL,
		Reader_pwd  varchar(20) NOT NULL
	)
	"
	,
	"
	CREATE TABLE Book 
	(
		Book_id     int NOT NULL auto_increment PRIMARY KEY,
		Book_name   varchar(20) NOT NULL,
		Book_number int NOT NULL,
		Book_price  float NOT NULL
	)
	"
	,
	"
	CREATE TABLE Book_in 
	(
		Book_in_id  int	NOT NULL auto_increment PRIMARY KEY,
		Book_in_name   varchar(20) NOT NULL,
		Book_in_number  int,
		Book_in_price  float NOT NULL		
	)
	"
	,
	"
	CREATE TABLE Book_out 
	(
		Book_out_id int NOT NULL auto_increment PRIMARY KEY,
		Book_out_name   varchar(20) NOT NULL,
		Book_out_number int,
		Book_out_price  float NOT NULL
	)
	");

?>