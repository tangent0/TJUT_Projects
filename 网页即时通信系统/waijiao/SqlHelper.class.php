<?php
	//对数据库的操作，
	class SqlHelper{
		
		public $conn;
		public $dbname="waijiao";
		public $localhost="localhost";
		public $username="root";
		public $password="123321";
		
		
		public function __construct(){
			$this->conn=mysql_connect("$this->localhost","$this->username","$this->password");
			if(!$this->conn){
				die("连接失败".mysql_error());
			}	
			mysql_select_db($this->dbname,$this->conn);	
		}
		
		public function execute_dql($sql){
		  	$res=mysql_query($sql,$this->conn) or die(mysql_error());
			return $res;
		}
		
		//返回的是数组,可以立即释放资源
		public function execute_dql2($sql){
			$arr=array();
		  	$res=mysql_query($sql,$this->conn) or die(mysql_error());
			//$i=0;
		  	while($row=mysql_fetch_assoc($res)){
		  		//将res是值导到了arr数组中
		  		//$arr[]可以直接这样写
		  		$arr[]=$row;
		  	}
		  	mysql_free_result($res);
		  	return $arr;
		}
		
			
		public function execute_dml($sql){
			$b=mysql_query($sql,$this->conn) or die(mysql_error());
			if(!$b){
				return 0; //失败
			}else{
				if(mysql_affected_rows($this->conn)>0){
					return 1;//表示执行成功
				}else{
					return 2;//表示没有行受到影响
				}
				
			}
			
		}

		//关闭连接的方法
		public	function close_connect(){
			if(!empty($this->conn)){
				mysql_close($this->conn);
			}
		}
	}	
?>