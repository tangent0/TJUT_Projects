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
<legend>�޸Ĺ���Ա</legend>
<center>
<form action="modifyBook.php" method="post" >
<?php
//�������ݿ������ļ�
include('conn.php');
//
$adminid=$_POST['adminid'];
$adminname=$_POST['adminname'];
$adminpwd=$_POST['adminpwd'];

$result = mysql_query("select * from Admin where Admin_id=$adminid");

//��ѯ�����ĿΪ0
if($result == false || mysql_num_rows($result) == 0){
	echo '����ʧ��','Admin_id = ',$adminid,'������','��<a href="modifyAdmin.html">����</a>';
	exit;
}

$result = mysql_query("update Admin set Admin_name='$adminname', Admin_pwd=$adminpwd where Admin_id=$adminid");
if($result == false){
	echo '�޸�ʧ��','��<a href="modifyAdmin.html">����</a>';
	exit;
}
echo '�޸ĳɹ�','Admin_id=',$adminid,'��<a href="modifyAdmin.html">����</a>';
?>
</center>

</fieldset>
</div>
</body>
</html>