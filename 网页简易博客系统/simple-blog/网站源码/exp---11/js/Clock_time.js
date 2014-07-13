
function startTime(){
  var d=new Date(); //创建一个Date对象
  var localTime = d.getTime();
  var localOffset=d.getTimezoneOffset()*60000; //获得当地时间偏移的毫秒数
  var utc = localTime + localOffset; //utc即GMT时间 
  var offset =Number(document.getElementById("city_zone").value); //时区
  var domain_time = utc + (3600000*offset); 
  var nd = new Date(domain_time); 
  document.getElementById("time").innerHTML=nd.toLocaleString();
  setTimeout("startTime()",1000);
}
