<?php
	require_once 'SqlHelper.class.php';
	
	class log_inService{
		function addMenber($username,$password,$email){
			$sql="insert into user (username,password,email) values ('$username','$password','$email')";
			$sqlhelper=new SqlHelper();
			$res=$sqlhelper->execute_dml($sql);
			$sqlhelper->close_connect();
			return $res;
			
		}
	}
?>