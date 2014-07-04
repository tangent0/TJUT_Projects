<html>
<head>
<title>用户注册</title>
<meta http-equiv="Content-Type" content="text/html;charset=utf-8">
<script src="js/log_in.js"></script>
</head>
<body style='background-color:yellow'>
<form action="log_inProcess.php" method="post" id="logForm">
<h1>新用户注册</h1><br>
<table width="400" border="0">
<tr>
<td align="center">用户名</td>
<td><input name="username" type="text" size="20" id="username"></td>
</tr>
<tr>
<td align="center">密码</td>
<td><input type="password" name="password" size="20" id="password"></td>
</tr>
<tr>
<td align="center">确认密码</td>
<td><input type="password"  name="Confirm_password" id="Confirm_password" size="20"></td>
</tr>
<tr>
<td align="center">Email</td>
<td><input type="text" name="email"  id="email"  size="20"></input></td>
</tr>
</table>
<input type="button" onclick="validate()" style="cursor:pointer" value="注册"></input><br>
</form>
如果您已经有账号，请点击<a href="index.php">这里登陆</a>
</body>
</html>
