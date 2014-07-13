<?php 
	$con = mysql_connect("localhost","root","");
 	if (!$con) 
		{ 
			die('Could not connect: ' . mysql_error()); 
		}
	if (mysql_query("CREATE DATABASE database_user_admin",$con))
 		{ 
			echo "Database created";
		 } 
	else 
		{ 
			echo "Error creating database: " . mysql_error();
 		}

  mysql_select_db("database_user_admin", $con);

  $cre_1= "CREATE TABLE table_user_pwd 
  (
   user_id int NOT NULL PRIMARY KEY AUTO_INCREMENT,
   user_name varchar(15),
   user_pwd varchar(15)
   )ENGINE=MyISAM";

  $cre_2= "CREATE TABLE table_admin_pwd 
  (
   admin_id int NOT NULL PRIMARY KEY AUTO_INCREMENT,
   admin_name varchar(15),
   admin_pwd varchar(15)
   )ENGINE=MyISAM";

//

  $cre_1_01 = "INSERT INTO table_user_pwd(user_id,user_name,user_pwd) VALUES (1,'tom','tom')";
  
  $cre_2_01 = "INSERT INTO table_admin_pwd(admin_id,admin_name,admin_pwd) VALUES (1,'admin','admin')";

// 
  mysql_query($cre_1,$con);
  mysql_query($cre_1_01,$con);

  mysql_query($cre_2,$con);
  mysql_query($cre_2_01,$con);

  mysql_close($con);
?>
