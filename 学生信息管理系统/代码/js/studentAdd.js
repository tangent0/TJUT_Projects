function studentvalidate(){
	var name=document.getElementById("name").value;
	var stuNum=document.getElementById("stuNum").value;
	var age=document.getElementById("age").value;
	var phone=document.getElementById("phone").value;
	var address=document.getElementById("address").value;
	var major=document.getElementById("major").value;

	var at=document.getElementById("email").value.indexOf("@");

	submitOK="true";
	if(name.length==""){
		alert("用户名不能为空");
		return false;
	}else if(stuNum==""){
		alert("学号不能为空");
		return false;
	}else if(age==""){
		alert("年龄不能为空");
		return false;
	}else if(phone==""){
		alert("电话不能为空");
		return false;
	}else if(address==""){
		alert("地址不能为空");
		return false;
	}else if(major==""){
		alert("专业不能为空");
		return false;
	}else if(at==-1){
		alert("邮箱的输入格式不正确");
		return false;
	}

	if(submitOK=="true"){
		document.getElementById("stuForm").submit();
	}
}
function gradevalidate(){
	var gradeNum=document.getElementById("gradeNum").value;
	var shuju=document.getElementById("shuju").value;
	var math=document.getElementById("math").value;
	var computer=document.getElementById("computer").value;
	var english=document.getElementById("english").value;
	var database=document.getElementById("database").value;
	submitOK="true";
	if(gradeNum==""){
		alert("学号不能为空");
		return false;
	}else if(shuju==""){
		alert("数据结构成绩不能为空");
		return false;
	}else if(math==""){
		alert("高等数学成绩不能为空");
		return false;
	}else if(computer==""){
		alert("计算机结构成绩不能为空");
		return false;
	}else if(english==""){
		alert("大学英语成绩不能为空");
		return false;
	}else if(database==""){
		alert("数据库设计成绩不能为空");
		return false;
	}

	if(submitOK=="true"){
		document.getElementById("gradeForm").submit();
	}
}

