<?php
	$name = $_POST['name'];
	$password = $_POST['pwd'];

//	if($name =="admin"&&$password="123"){
		session_start();
		$_SESSION['name']=$name;
		header("Location:friendList.php");
//	}else{
//		header("Location:login.php");
//	}
?>