<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head><meta http-equiv="content-type" content="text/html;charset=utf-8"/></head>
<style type="text/css">
body{background-color:#ececec;}
.main{position:absolute;top:40px;left:450px;font:white;}
</style>
<body>
<div class="main">
<h1>登录系统</h1>
<form  action="loginProcess.php" method="post">
用户名<input type="text" name="username">
<p>密&nbsp&nbsp码<input type="password" name="password"></p>
验证码<input type="text" name="checkCode" size="5"/>
<img src="checkCode.php" onclick="this.src='checkCode.php?aa='+Math.random()" title="看不清,换一张" style="cursor:pointer"/><br/>
<p><input type="submit" name="submit" value="登录"></p>
</form>
<a href="forgot.php">忘了密码？</a> 
<a href="SignUp.php">注册新用户</a>
</body>
</html>

<?php 
	//接收errno
	require_once 'cookie.php';
	if(!empty($_GET['errno'])){	
		//接收错误编号
		$errno=$_GET['errno'];
		if($errno==1){
			echo "<br/><font color='red' size='3'>你的用户名或者密码错误</font>";
		}elseif($errno==2){
			echo "<br/><font color='red' size='3'>验证码错误</font>";
		}
	}
?>
</div>