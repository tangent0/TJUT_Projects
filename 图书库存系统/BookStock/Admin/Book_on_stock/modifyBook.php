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

//����Ƿ��¼����û��¼��ת���¼����
if(!isset($_SESSION['userid'])){
	header("Location:../login.php");
	exit();
}

?>

<div>
<fieldset>
<legend>�޸�ͼ��</legend>
<center>

<?php
//�������ݿ������ļ�
include('conn.php');
//
$bookid=$_POST['bookid'];
$bookname=$_POST['bookname'];
$booknumber=$_POST['booknumber'];
$bookprice=$_POST['bookprice'];

$result = mysql_query("select * from Book where Book_id=$bookid");

//��ѯ�����ĿΪ0
if($result == false || mysql_num_rows($result) == 0){
	echo '����ʧ��','Book_id = ',$bookid,'������','��<a href="modifBook.html">����</a>';
	exit;
}

$result = mysql_query("update Book set Book_name='$bookname', Book_number=$booknumber, Book_price=$bookprice where Book_id=$bookid");
if($result == false){
	echo '�޸�ʧ��','��<a href="modifyBook.php">����</a>';
	exit;
}
echo '�޸ĳɹ�','Book_id=',$bookid,'��<a href="./modifyBook.html">����</a>';
?>
</center>

</fieldset>
</div>
</body>
</html>