<?php
session_start();

//注销登录
if(@$_GET['action'] == "logout"){
	unset($_SESSION['userid']);
	unset($_SESSION['username']);
	echo '<center>';
	echo '注销登录成功！点击此处 <a href="login.html">登录</a>';
	exit;
}

//登录
if(!isset($_POST['submit'])){
	exit('非法访问!');
}
$username =($_POST['username']);
$password =($_POST['password']);

//包含数据库连接文件
include('conn.php');
 
//检测用户名及密码是否正确
$check_query = mysql_query("select * from Reader where Reader_name='$username' and Reader_pwd='$password' limit 1");

if(@$result = mysql_fetch_array($check_query)){
	//登录成功
	$_SESSION['username'] = $username;
	$_SESSION['userid'] = $result['Reader_id'];
	echo '<center>';
	echo $username,' 欢迎你！进入 <a href="./transaction_page.html">用户中心</a><br />';
	echo '点击此处 <a href="login.php?action=logout">注销</a> 登录！<br />';
	exit;
} else {
	echo '<center>';
	exit('用户名或密码错误，登录失败！点击此处 <a href="./login.html">返回</a> 重试');
}


?>