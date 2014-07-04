<body style='background-color:#ccc'>
<?php 
	header("Content-type:text/html;charset=utf-8");
	require_once 'cookie.php';
	require_once 'SqlHelper.class.php';
	
	session_start();
	if(!isset($_SESSION['username'])){
		header("Location:index.php");
		exit();
	}

	if(!empty($_GET['username'])){
		echo "登录成功!!";
		echo "欢迎你".$_SESSION['username'].".</br>";
		getLastTime();
	}



?>
<hr/>
<script src="js/jquery.1.4.2-min.js" type="text/javascript"></script>
<script src="js/studentAdd.js"></script>
<script type="text/javascript" >
$(document).ready(function(){
		$(".left ul li").click(function(){
			var index = $(this).index();
			$(this).addClass("selected").siblings().removeClass("selected");
			$(".right div").eq(index).show().siblings().hide();
		});
});

</script>
<link rel="stylesheet" href="css/main.css">
<div class="left">
	<ul>
		<li>首页</li>
		<li>学生基本信息</li>
		<li>增加学生</li>
		<li>学生成绩登记</li>
		<li>成绩显示</li>
		<li><a href="index.php" style="text-decoration:none;color:black;">退出系统</a></li>
	</ul>
</div>
<div class="right"> 
	<div>欢迎进入学生管理系统</div>
	 <div class="hide">
	 <?php
		$sqlhelper = new SqlHelper();
		$sql = "select * from student";
		$res = $sqlhelper->execute_dql2($sql);
		echo "<table border=1 width=100% cellpadding=2 cellspacing=0 >";
		echo "<tr><td align='center'>姓名</td><td align='center'>学号</td><td align='center'>出生日期</td><td align='center'>性别</td><td align='center'>电话</td><td align='center'>电子邮箱</td><td align='center'>地址</td><td align='center'>专业</td><td></td><td></td></tr>";
		while($row = mysql_fetch_assoc($res)){
			echo "<tr><td align='center'>{$row['name']}</td><td align='center'>{$row['stuNum']}</td><td align='center'>{$row['age']}</td><td align='center'>{$row['sex']}</td><td align='center'>{$row['phone']}</td><td align='center'>{$row['email']}</td><td align='center'>{$row['address']}</td><td align='center'>{$row['major']}</td><td align='center'><a href='studentUpdate.php?id={$row['id']}'>修改</a></td><td align='center'><a href='studentDel.php?id={$row['id']}'>删除</a></td></tr>";
		
		}
		echo "</table>";
		?>
	 </div>
	 <div class="hide">
		<form action="stuProcess.php" method="post" id="stuForm">
		<h1>学生信息录入</h1><br>
		<table width="400" border="0">
		<tr>
		<td align="center">姓名</td>
		<td><input name="name" type="text" size="40" id="name"></td>
		</tr>
		<tr>
		<td align="center">学号</td>
		<td><input type="text" name="stuNum" size="40" id="stuNum"></td>
		</tr>
		<tr>
		<td align="center">性别</td>
		<td>男<input type="radio" name='sex' value='男' checked> 女<input type="radio" name='sex' value="女" ></td>
		</tr>
		<tr>
		<td align="center">出生年月</td>
		<td><input type="text" name="age"  id="age"  size="40"></input></td>
		</tr>
		<tr>
		<td align="center">电话</td>
		<td><input type="text" name="phone"  id="phone"  size="40"></input></td>
		</tr>
		<tr>
		<td align="center">email</td>
		<td><input type="email" name="email"  id="email"  size="40"></input></td>
		</tr>
		<tr>
		<td align="center">地址</td>
		<td><input type="text" name="address"  id="address"  size="40"></input></td>
		</tr>
		<tr>
		<td align="center">专业</td>
		<td><input type="text" name="major"  id="major"  size="40"></input></td>
		</tr>
		</table>
		<input type="button" onclick="studentvalidate()" style="cursor:pointer" value="提交"></input><br>
		</form>

	 </div>
	 <div class="hide">
		
		<form action="gradeProcess.php" method="post" id="gradeForm">
		<h1>学生成绩登记</h1><br>
		<table width="400" border="0">
		<tr>
		<td align="center">学号</td>
		<td><input type="text" name="stuNum" size="40" id="gradeNum"></td>
		</tr>
		<tr>
		<td align="center">数据结构</td>
		<td><input type="text" name="shuju"  id="shuju"  size="40"></input></td>
		</tr>
		<tr>
		<td align="center">高等数学</td>
		<td><input type="text" name="math"  id="math"  size="40"></input></td>
		</tr>
		<tr>
		<td align="center">计算机结构</td>
		<td><input type="email" name="computer"  id="computer"  size="40"></input></td>
		</tr>
		<tr>
		<td align="center">大学英语</td>
		<td><input type="text" name="english"  id="english"  size="40"></input></td>
		</tr>
		<tr>
		<td align="center">数据库设计</td>
		<td><input type="text" name="database"  id="database"  size="40"></input></td>
		</tr>
		</table>
		<input type="button" onclick="gradevalidate()" style="cursor:pointer" value="提交"></input><br>
		</form>

	 </div>
	 <div class="hide">
			 <?php
				$grade = new SqlHelper();
				$sql1 = "select s.name,g.* from student s,grade g where s.stuNum=g.stuNum";
				$res1 = $grade->execute_dql2($sql1);
				echo "<table border=1 width=100% cellpadding=0 cellspacing=0 >";
				echo "<tr><td align='center'>姓名</td><td align='center'>学号</td><td align='center'>数据结构</td><td align='center'>高等数学</td><td align='center'>计算机结构</td><td align='center'>大学英语</td><td align='center'>数据库设计</td></tr>";
				while($row = mysql_fetch_assoc($res1)){
					echo "<tr><td align='center'>{$row['name']}</td><td align='center'>{$row['stuNum']}</td><td align='center'>{$row['shuju']}</td><td align='center'>{$row['math']}</td><td align='center'>{$row['computer']}</td><td align='center'>{$row['engish']}</td><td align='center'>{$row['db']}</td></tr>";
				
				}
				echo "</table>";
			?>
	</div>
	 <div class="hide">退出系统</div>
</div>