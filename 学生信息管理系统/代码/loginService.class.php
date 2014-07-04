<?php
	require_once 'SqlHelper.class.php';
	class loginService{
		function checkAdmin($username,$password){
			$sql="select username,password from user where username='$username'";
			$sqlhelper=new SqlHelper();
			$res=$sqlhelper->execute_dql2($sql);
			
			if($row=mysql_fetch_assoc($res)){
				if($password==$row['password']){
					return $row['username'];
				}
			}
			mysql_free_result($res);
			$sqlhelper->close_connect();
			return false;
		}
	}
?>