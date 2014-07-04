<?php
	require_once 'SqlHelper.class.php';
	$id = $_GET['id'];
	$stuDel = new SqlHelper();
	$sql = "delete from student where id=$id";
	$res = $stuDel->execute_dml($sql);
	if($res){
		echo "删除成功！";
	}
	echo '<a href="manage.php?username=$username">返回</a>';

?>