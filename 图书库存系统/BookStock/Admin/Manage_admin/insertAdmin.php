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
<legend>��ӹ���Ա</legend>
<center>
<?php
//�������ݿ������ļ�
include('conn.php');
//
$adminname=$_POST['adminname'];
$adminpwd=$_POST['adminpwd'];

$result = mysql_query("insert into Admin(Admin_name,Admin_pwd) values ('$adminname','$adminpwd')");
if(!$result){
	echo '����ʧ��','��<a href="insertAdmin.html">����</a>';
	exit;
}
echo '����ɹ�','Admin_name=',$adminname ,'��<a href="insertAdmin.html">����</a>';
?>
</center>
</form>

</center>

</fieldset>
</div>
</body>
</html>