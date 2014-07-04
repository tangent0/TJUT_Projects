<?php
	require_once 'SqlHelper.class.php';
	$name = $_POST['name'];
	$stuNum = $_POST['stuNum'];
	$sex = $_POST['sex'];
	$age = $_POST['age'];
	$phone = $_POST['phone'];
	$email = $_POST['email'];
	$address = $_POST['address'];
	$major = $_POST['major'];

	$sql = "insert into student values (null,'$name','$stuNum','$age','$sex','$phone','$email','$address','$major')";

	$stuAdd = new SqlHelper();
	$res = $stuAdd->execute_dml($sql);
	if($res==1){
		echo "添加成功";
	}else{
		echo "添加失败";
	}
	$stuAdd->close_connect();
	session_start();
	$username=$_SESSION['username'];
	echo '<a href="manage.php?username=$username">返回</a>';

?>