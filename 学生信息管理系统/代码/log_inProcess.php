<?php
	require_once 'log_inService.class.php';
	
	$username=$_POST['username'];
	$password=$_POST['password'];
	$email = $_POST['email'];
	
	$log_inservice=new log_inService();
	$res=$log_inservice->addMenber($username,$password,$email);
	if($res==1){
		header("Location: ok.php");
		exit();
		
	}else{
		header("Location: error.php");
		exit();
	}
	
	$sqlhelper->close_connect();
	
?>