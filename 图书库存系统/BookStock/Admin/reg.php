<?php
if(!isset($_POST['submit'])){
	exit('�Ƿ�����!');
}
$username = $_POST['username'];
$password = $_POST['password'];

//ע����Ϣ�ж�
if(!preg_match('/^[\w\x80-\xff]{3,15}$/', $username)){
	exit('�����û��������Ϲ涨��<a href="parent.location.href=document.referrer;">����</a>');
}
if(strlen($password) < 3){
	exit('�������볤�Ȳ����Ϲ涨��<a href="parent.location.href=document.referrer;">����</a>');
}

//�������ݿ������ļ�
include('conn.php');
//����û����Ƿ��Ѿ�����
$check_query = mysql_query("select Admin_name from Admin where Admin_name='$username' limit 1");
if(mysql_fetch_array($check_query)){
	echo '�����û��� ',$username,' �Ѵ��ڡ�<a href="../index.php">����</a>';
	exit;
}
//д������
$password = ($password);
$regdate = time();
$sql = "INSERT INTO Admin VALUES(0,'$username','$password')";
if(mysql_query($sql,$conn)){
	exit('�û�ע��ɹ�������˴� <a href="login.html">��¼</a>');
} else {
	echo '��Ǹ���������ʧ�ܣ�',mysql_error(),'<br />';
	echo '����˴� <a href="../index.php">����</a> ����';
}
?>
