<?php
	require_once 'SqlHelper.class.php';
	session_start();
	$content = $_POST['content'];
	$sender = $_SESSION['name'];
	$getter = $_POST['getter'];

	$sql = "insert into messages (sender,getter,content) values ('$sender','$getter','$content')";

	$sqlHelper = new SqlHelper();

	$result = $sqlHelper->execute_dml($sql);
/*	if($result==1){
		$query = "select * from messages where sender='$sender' and getter='$getter' order by sendTime desc limit 0,2";
		$array = $sqlHelper->execute_dql2($query);
		$num = count($array);
		$messageInfo = "<meses>";
		for($i=0;$i<$num;$i++){
			$row=$array[$i];
			$messageInfo.="<sender>{$row['sender']}</sender><getter>{$row['getter']}</getter><content>{$row['content']}</content><time>{$row['sendTime']}</time>";
		}
		
		$messageInfo .= "</meses>";

		echo $messageInfo;

	}else{
		echo "添加失败";
	}*/

?>