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
	$id = $_POST['id'];

	$sql = "update student set
	name='$name',stuNum='$stuNum',age='$age',sex='$sex',phone='$phone',email='$email',address='$address',major='$major' where id=$id";

	$stuUp = new SqlHelper();
	$res = $stuUp->execute_dml($sql);
	if($res==1){
		echo "修改成功";
	}else{
		echo "添加失败";
	}
	$stuUp->close_connect();
	session_start();
	$username=$_SESSION['username'];
	echo '<a href="manage.php?username=$username">返回</a>';

?>