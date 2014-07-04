function validate(){
	var username=document.getElementById("username").value;
	var initiate=document.getElementById("password").value;
	var second=document.getElementById("Confirm_password").value;
	var at=document.getElementById("email").value.indexOf("@");
	submitOK="true";
	if(username.length>10){
		alert("用户名太长!!!");
		return false;
	}else if(username==""){
		alert("用户名不能为空");
		return false;
	}else if(initiate==""){
		alert("密码不能为空");
		return false;
	}else if(initiate!=second){
		alert("两次输入的密码不一样");
		return false;
	}else if(at==-1){
		alert("邮箱的输入格式不正确");
		return false;
	}

	if(submitOK=="true"){
		document.getElementById("logForm").submit();
	}
}

