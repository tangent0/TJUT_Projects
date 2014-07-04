<?php
	function getLastTime(){
		date_default_timezone_set("Asia/Chongqing");
		if(!empty($_COOKIE['last_visit'])){
			echo "你上次登陆时间是<br/>".$_COOKIE['last_visit'];
			//更新时间
			setCookie("last_visit",date("Y-m-d H:i:s"),time()+24*3600*3600);
		}else{
			echo "你是第一次登陆<br/>";
			setCookie("last_visit",date("Y-m-d H:i:s"),time()+24*3600*3600);
		}
	}
	function getCookieVal($key){
		if(empty($_COOKIE[$key])){
			return "";
		}else{
			return $_COOKIE[$key];
		}
	}
	function checkUserValiate(){
		session_start();
		if(empty($_SESSION['loginuser'])){
		header("Location: login.php?errno=1");
	}
	}
?>