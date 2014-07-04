<?php
	$con = mysql_connect("localhost","root","");
	if (!$con)	{
		die('Could not connect: ' . mysql_error());
	}
	
	//Drop database
	mysql_query("DROP DATABASE BookStock_Database", $con);

	// Create database	
	mysql_query("CREATE DATABASE BookStock_Database",$con);
	/*
	if (mysql_query("CREATE DATABASE BookStore_Database",$con))	{
		echo "Database created";
	}	else	{
		echo "Error creating database: " . mysql_error();
	}
	*/
	
	// Create table in my_db database
	mysql_select_db("BookStock_Database", $con);
	
	include 'creat_table.php';
	foreach($creat_table_sql_array as $creat_sql)
		mysql_query($creat_sql, $con);
	
	include 'init_table.php';
	foreach($init_table_sql_array as $init_sql)
		mysql_query($init_sql, $con);

	mysql_close($con);
?>