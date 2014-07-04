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
<legend>添加图书</legend>
<center>
<?php
//包含数据库连接文件
include('conn.php');
//
$bookname=$_POST['bookname'];
$booknumber=$_POST['booknumber'];
$bookprice=$_POST['bookprice'];

$result = mysql_query("insert into Book_out(Book_out_name,Book_out_number,Book_out_price) values ('$bookname',$booknumber,$bookprice)");
if(!$result){
	echo '插入失败','。<a href="./insertBook.html">返回</a>';
	exit;
}
echo '插入成功','Book_name=',$bookname,'。<a href="./insertBook.html">返回</a>';
?>
</center>
</form>

</center>

</fieldset>
</div>
</body>
</html>