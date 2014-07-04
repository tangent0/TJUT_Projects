<html>
<head>
<meta http-equiv="content-type" content="text/html;charset=utf-8"/>
<script type="text/javascript" src="js/jquery.1.4.2-min.js"></script>
<script type="text/javascript">
	$(document).ready(function(){
		$("#friend li").hover(
			function(){
				$(this).css("color","red");
			},
			function(){
				$(this).css("color","black");
			}
		)
		$("#friend li").click(function(){
			var value = $(this).html();
			window.open("chat.php?getter="+value);
		})
	})
</script>
</head>

<h1>friends</h1>
<ul id="friend">
<li>Joey</li>
<li>admin</li>
<li>James</li>
<li>Monica</li>
<li>Ross</li>
</ul>
</body>
</html>