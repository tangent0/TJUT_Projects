<body style='background-color:yellow'>
<?php
	require_once 'SqlHelper.class.php';
	$stuUp = new SqlHelper();
	$id=$_GET['id'];
	$sql="select * from student where id=$id";
	$res=$stuUp->execute_dql2($sql);
	$row=mysql_fetch_assoc($res);
?>
<script src="js/studentAdd.js"></script>
<form action="stuUpProcess.php" method="post" id="stuForm">
<h1>学生信息修改</h1><br>
<table width="400" border="0">
<tr>
<td align="center">学生姓名</td>
<td><input name="name" type="text" size="40" id="name" value="<?php echo $row['name']?>"></td>
</tr>
<tr>
<td align="center">学号</td>
<td><input type="text" name="stuNum" size="40" id="stuNum" value="<?php echo $row['stuNum']?>"></td>
</tr>
<tr>
<td align="center">性别</td>
<td>男<input type="radio" name='sex' value='男' checked> 女<input type="radio" name='sex' value="女" ></td>
</tr>
<tr>
<td align="center">出生年月</td>
<td><input type="text" name="age"  id="age"  size="40" value="<?php echo $row['age']?>"></input></td>
</tr>
<tr>
<td align="center">电话</td>
<td><input type="text" name="phone"  id="phone"  size="40" value="<?php echo $row['phone']?>"></input></td>
</tr>
<tr>
<td align="center">email</td>
<td><input type="email" name="email"  id="email" size="40" value="<?php echo $row['email']?>"></input></td>
</tr>
<tr>
<td align="center">地址</td>
<td><input type="text" name="address" id="address" size="40" value="<?php echo $row['address']?>"></input></td>
</tr>
<tr>
<td align="center">专业</td>
<td><input type="text" name="major" id="major" size="40" value="<?php echo $row['major']?>"></td>
</tr>
</table>
<input type="hidden" name="id" value="<?php echo $id?>"/>
<input type="button" onclick="validate()" style="cursor:pointer" value="提交"></input>
<?php echo '<a href="manage.php?username=$username">返回</a>';?><br>
</form>
