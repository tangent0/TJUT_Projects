<?php
	require_once 'loginService.class.php';
	$username=$_POST['username'];
	$password=$_POST['password'];

	//验证码
	$checkCode=$_POST['checkCode'];
	session_start();
	if($checkCode!=$_SESSION['myCheckCode']){
		header("Location: index.php?errno=2");
		exit();
	}
	
	$loginservice = new loginService();
	if($username=$loginservice->checkAdmin($username,$password)){
		session_start();
		$_SESSION['username']=$username;
		header("Location:manage.php?username=$username");
		exit();
	}else{
		header("Location:index.php?errno=1");
		exit();
	}
?>
