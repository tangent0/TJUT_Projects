<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gbk" />
<title></title>
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

<?php
session_start();

//检测是否登录，若没登录则转向登录界面
if(!isset($_SESSION['userid'])){
	header("Location:../login.php");
	exit();
}

?>

<div>
<fieldset>
<legend>修改图书</legend>
<center>
<form action="modifyBook.php" method="post" >
<?php
//包含数据库连接文件
include('conn.php');
//
$bookid=$_POST['bookid'];
$bookname=$_POST['bookname'];
$booknumber=$_POST['booknumber'];
$bookprice=$_POST['bookprice'];

$result = mysql_query("select * from Book_out where Book_out_id=$bookid");

//查询结果数目为0
if($result == false || mysql_num_rows($result) == 0){
	echo '查找失败','Book_id = ',$bookid,'不存在','。<a href="./modifyBook.html">返回</a>';
	exit;
}

$result = mysql_query("update Book_out set Book_out_name='$bookname', Book_out_number=$booknumber, Book_out_price=$bookprice where Book_out_id=$bookid");
if($result == false){
	echo '修改失败','。<a href="modifyBook.html">返回</a>';
	exit;
}
echo '修改成功','Book_id=',$bookid,'。<a href="modifyBook.html">返回</a>';
?>
</center>

</fieldset>
</div>
</body>
</html>