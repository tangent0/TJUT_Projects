<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gbk" />
<title>��ҳ</title>
  <style type="text/css">
    html{font-size:12px;}
	fieldset{width:300px; margin: 0 auto;}
	legend{font-weight:bold; font-size:14px;}
	.label{float:left; width:70px; margin-left:10px;}
	.left{margin-left:80px;}
	.input{width:150px;}
	span{color: #666666;}
  </style>

</head>
<body>

<div>
<fieldset>
<?php
	include('connect_to_db.php');
?>

<h3>ͼ����ϵͳ</h3>

<form name="LoginForm1" method="post" action="./Admin/login.html">
<input type="submit" name="submit" value="����Ա���">
</form>

<form name="LoginForm2" method="post" action="./Reader/login.html">
<input type="submit" name="submit" value="�������">
</form>

<a style="text-decoration:none;" href="./writePage.php">
<input type="button" name="submit" value="�˳�">
</a>

</fieldset>
</div>
</body>
</html>