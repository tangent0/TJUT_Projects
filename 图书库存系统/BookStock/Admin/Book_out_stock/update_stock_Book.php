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
<legend>用入库表更新库存表</legend>
<center>
<?php
//包含数据库连接文件
include('conn.php');

/*fail for version problem
$result = mysql_query("update Book t1 set t1.Book_number = t1.Book_number + t2.Book_in_number
					   from Book_in t2
					   where t1.Book_name = t2.Book_in_name
					   ");
*/

$result = mysql_query("update (Book t1 inner join Book_out t2 on t1.Book_name=t2.Book_out_name)
                       set t1.Book_number=t1.Book_number-t2.Book_out_number
					   ");
//操作失败
if($result == false){
	echo '更新图书数量失败','。<a href="./selectAllBook.php">返回</a>';
	exit;
}else {
	echo '更新图书数量成功','。<a href="./selectAllBook.php">返回</a><p/>';
}

$result = mysql_query("insert into Book(Book_name, Book_number, Book_price)
					   select Book_out_name, 0, Book_out_price					   
					   from Book_out
					   where Book_out_name
					   not in
					   (select Book_name from Book)"); //use 0, don't insert -Book_out_number for actual situation
//操作失败
if($result == false){
	echo '更新图书记录失败','。<a href="./selectAllBook.php">返回</a>'; //javascript:history.back(-1) 回退但不能刷新
	exit;
}else {
	echo '更新图书记录成功','。<a href="./selectAllBook.php">返回</a>';
}

?>
</center>
</form>

</center>

</fieldset>
</div>
</body>
</html>