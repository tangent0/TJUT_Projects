<?php
	require_once 'SqlHelper.class.php';
	$getter = $_GET['getter'];
	session_start();
	$sender = $_SESSION['name'];
	$sqlHelper = new SqlHelper();
	$query = "select * from messages";
	
	$array = $sqlHelper->execute_dql2($query);
	$num = count($array);
	$messageInfo = "";
	
	for($i=0;$i<$num;$i++){
		$row=$array[$i];
		$messageInfo .=$row['sender']."  ".$row['sendTime']."\r\n".$row['content']."\r\n";
	}
		
?>
<html>
<head><meta http-equiv="content-type" content="text/html;charset=utf-8"/></head>
<script type="text/javascript" src="js/jquery.1.4.2-min.js"></script>

<script type="text/javascript">
	$(document).ready(function(){
		$(".post").click(function(){
			var content = $(".reply").val();
			
			$.ajax({
				type:"POST",
				url:"chatAction.php",
				data:"content="+content+"&getter=<?php echo $getter; ?>",
				success:function(msg){
				//	var sender = $(msg).children("sender").text();
				//	var content = $(msg).children("content").text();
				//	var time = $(msg).children("time").text();
				//	$(".content").html(sender+"   "+time+"\r\n"+content);
				}
			})
			
		});
	})
</script>

<body>
<center>
<h1>You are chatting to <?php echo $_GET['getter']?></h1>

<textarea name="content" style="width:500px;height:300px;" class="content"><?php echo $messageInfo ?></textarea><br/><br/><br/>

reply:<input type="text" size="50px" class="reply"><br/>
<input type="submit" value="post" class="post">
</center>
</body>
</html>