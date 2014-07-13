<?xml version = "1.0" encoding = "utf-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns = "http://www.w3.org/1999/xhtml">
<head><title>register.php</title>
</head>

<body style="background-color:transparent">

<?php
 $name=$_POST["name"];
 $password=$_POST["pwd"];
 $gender=$_POST["gender"];
 $age=$_POST["age"];
 $email=$_POST["email"];
 $favor=$_POST["favor"];
?>


 <?php
$con = mysql_connect("localhost","root","");
if (!$con) 
{ 
  die('Could not connect: ' . mysql_error()); 
}
$er = mysql_select_db("database_user_admin",$con);
if (!$er) {
    print "Error - Could not select the cars database";
    exit;
}
 $query = "SELECT user_name,user_pwd FROM table_user_pwd WHERE user_name='$name'";
 $result = mysql_query($query,$con);
 $num_rows = mysql_num_rows($result);
 //echo $num_rows;
 if($num_rows==0)
 {
  $cre_1_03 = "INSERT INTO table_user_pwd(user_id,user_name,user_pwd) VALUES (2,'$name','$password')";
  mysql_query($cre_1_03,$con);
?>

  <p>Your information is as follow,<br />and it's sended into the database,thank you.</p>
  <table border="border">
     <tr><th>Please Input your name </th> <td><?php echo $name ?> </td></tr> 
     <tr><th>Password               </th> <td><?php echo $password ?>  </td></tr>
     <tr><th>gender      </th> <td><?php echo $gender ?> </td></tr>
     <tr><th>Age</th> <td> <?php echo $age ?>   </td></tr>
     <tr><th>Email Address</th> <td><?php echo $email ?>  </td></tr>
     <tr>
     <th>favor</th>
     <td>
     <?php
      foreach($favor as $favor_value)echo  "$favor_value,</br>";
     ?>
     </td>
     </tr>
  </table>

<?php
 }
 else echo "<strong>the user has been already existed,<br />please try another</strong>";
?>
</body>

</html>