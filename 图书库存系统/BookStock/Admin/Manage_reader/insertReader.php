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
<legend>添加读者</legend>
<center>
<?php
//包含数据库连接文件
include('conn.php');
//
$readername=$_POST['readername'];
$readerpwd=$_POST['readerpwd'];

$result = mysql_query("insert into Reader(reader_name,reader_pwd) values ('$readername','$readerpwd')");
if(!$result){
	echo '插入失败','。<a href="./insertReader.html">返回</a>';
	exit;
}
echo '插入成功','Reader_name=',$readername,'。<a href="./insertReader.html">返回</a>';
?>
</center>
</form>

</center>

</fieldset>
</div>
</body>
</html>