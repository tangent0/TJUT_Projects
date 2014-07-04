<?php
	require_once 'SqlHelper.class.php';
	$stuNum = $_POST['stuNum'];
	$shuju = $_POST['shuju'];
	$math = $_POST['math'];
	$computer = $_POST['computer'];
	$english = $_POST['english'];
	$database = $_POST['database'];

	$sql = "insert into grade values (null,'$stuNum','$shuju','$math','$computer','$english','$database')";

	$gradeAdd = new SqlHelper(); //实例化对象
	$res = $gradeAdd->execute_dml($sql);
	if($res==1){
		echo "添加成功";
	}else{
		echo "添加失败";
	}
	$gradeAdd->close_connect();
	session_start();
	$username=$_SESSION['username'];
	echo '<a href="manage.php?username=$username">返回</a>';

?>