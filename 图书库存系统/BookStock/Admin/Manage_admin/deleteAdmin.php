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
<legend>ɾ��ͼ��</legend>
<center>
<?php
//�������ݿ������ļ�
include('conn.php');
//
$adminid=$_POST['adminid'];
$result = mysql_query("delete from Admin where Admin_id=$adminid");
if($result == false){
	echo 'ɾ��ʧ��','��<a href="./deleteAdmin.html">����</a>';
	exit;
}
echo 'ɾ���ɹ�','Admin_id = ',$adminid,'��<a href="./deleteAdmin.html">����</a>';
?>
</center>
</form>

</center>

</fieldset>
</div>
</body>
</html>