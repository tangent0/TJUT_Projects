<body style='background-color:#7FFFD4'>
<meta http-equiv="content-type" content="text/html;charset=utf-8"/>
<script src="js/jquery.1.4.2-min.js" type="text/javascript"></script>
<script type="text/javascript" >
$(document).ready(function(){
		$(".pleft ul li").click(function(){
			var index = $(this).index();
			$(this).addClass("selected").siblings().removeClass("selected");
			$(".pright div").eq(index).show().siblings().hide();
		});
});

</script>
<link rel="stylesheet" href="css/main.css"/>
<div class='pleft'>
	<ul>
	<li class="selected">找回密码</li>
	<li>修改密码</li>
	</ul>
</div>

<div class='pright'>
	<div>
	<form action="forgot.php" method="get">
	请输入您的邮箱号码<input type="text" name="email"><br/>
	<input type="submit" value="提交"/>
	</form>
	<?php 
		header("Content-type:text/html;charset=utf-8");
		require_once 'SqlHelper.class.php';
		$selPass = new SqlHelper();
		if(isset($_GET['email'])){
			$email = $_GET['email'];
			$sql = "select password from user where email='$email'";
			$res=$selPass->execute_dql2($sql);
			$pass = mysql_fetch_assoc($res);
			
			echo "<h1>你的密码是：".$pass['password']."</h1>";
		}
	?>
	</div>
	<div class="hide">
		<form action="forgot.php" method="get">
			请输入用户名<input type="text" name="username"><br/>
			请输入新密码<input type="password" name="fnewpass"><br/>
			请再输入新密码<input type="password" name="snewpass"><br/>
			<input type="submit" value="提交"/>
		</form>
		<?php 
			header("Content-type:text/html;charset=utf-8");
			require_once 'SqlHelper.class.php';
			$changePass = new SqlHelper();
			if(!empty($_GET['username'])&&!empty($_GET['fnewpass'])&&!empty($_GET['snewpass'])){
				$username = $_GET['username'];
				$fnewpass = $_GET['fnewpass'];
				$snewpass = $_GET['snewpass'];
			
				if($fnewpass!=$snewpass){
					echo "两次密码输入不一样！！";
					exit;
				}
				$sql = "select id from user where username='$username'";

				$res=$changePass->execute_dql2($sql);
				$row = mysql_fetch_assoc($res);
				$id = $row['id'];
		
				$sql1 ="update user set password='$fnewpass' where id='$id'";
			
				$res1=$changePass->execute_dml($sql1);
				if($res1==1){
					echo "修改成功";
				}else{
					echo "修改失败";
				}
			}
		?>
	</div>
</div>
<br/><br/>
<a href="index.php">返回登陆界面</a>;