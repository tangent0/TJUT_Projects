<?xml version = "1.0" encoding = "utf-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns = "http://www.w3.org/1999/xhtml">
<head> <title> admin_login.php </title>  
</head>

<body>

<?php

session_start();

$admin= $_POST['admin'];
$password = $_POST['pwd'];
if(empty($admin) or empty($password)){
 echo '用户名和密码不能为空';
 exit();
}

// Connect to MySQL

$con = mysql_connect("localhost", "root", "");
if (!$con) {
     print "Error - Could not connect to MySQL";
     exit;
}

// Select the cars database

$er = mysql_select_db("database_user_admin",$con);
if (!$er) {
    print "Error - Could not select the cars database";
    exit;
}


$query="SELECT * FROM table_admin_pwd WHERE admin_name='$admin' and admin_pwd='$password'";

$result = mysql_query($query,$con) or die('Query failed: ' . mysql_error());

$row=mysql_num_rows($result);

if($row>0){
 $_SESSION['valid_admin']=$admin;

?>

<?php

 $filevar=fopen("admin_login.txt","w")or die("Error - file cannot be openned");
 file_put_contents("admin_login.txt",$admin);
 fclose($filevar);
 
 header("Location: admin.php"); //登陆成功在这里转向
}else {
 echo '用户名或密码错误'.'<br />';
 echo "<a href='../index.php'>返回</a>";
 }
?>

</body>


</html>