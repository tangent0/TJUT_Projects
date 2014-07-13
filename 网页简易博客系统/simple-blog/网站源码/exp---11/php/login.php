<?xml version = "1.0" encoding = "utf-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns = "http://www.w3.org/1999/xhtml">
<head> <title> login.php </title>  
<script type='text/javascript'>
 var c=3,t;
 function timedCount()
 {
  if(c!=-1)
  {
   document.getElementById('second').innerHTML=c;
   c=c-1;
   t=setTimeout('timedCount()',500)
  }
  else
  {
   clearTimeout(t); alert('logging succeeded'); 
   location='../index.php'; 
   
   //window.opener=null; window.open('','_self'); window.close();
  }
 }
</script> 
</head>

<body onload="timedCount();">

<?php

session_start();

$user=$_POST['username'];
$password=$_POST['pwd'];
if(empty($user) or empty($password)){
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
    print "Error - Could not select the database_user_admin database";
    exit;
}


$query="SELECT * FROM table_user_pwd WHERE user_name='$user' and user_pwd='$password'";

$result = mysql_query($query,$con) or die('Query failed: ' . mysql_error());

$row=mysql_num_rows($result);

if($row>0){
 $_SESSION['valid_user']=$user;

?>

<?php
 echo "<p>logging,be back in <span id='second'></span> second(s)...</p>";

 $filevar=fopen("greeting.txt","w")or die("Error - file cannot be openned");
 file_put_contents("greeting.txt",$user);
 fclose($filevar);
 
 //header("Location:../index.php"); //登陆成功在这里转向
}else {
 echo '用户名或密码错误'.'<br />';
 echo "<a href='../index.php'>返回</a>";
 }
?>

</body>


</html>