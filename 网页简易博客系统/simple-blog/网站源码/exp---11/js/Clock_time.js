
function startTime(){
  var d=new Date(); //����һ��Date����
  var localTime = d.getTime();
  var localOffset=d.getTimezoneOffset()*60000; //��õ���ʱ��ƫ�Ƶĺ�����
  var utc = localTime + localOffset; //utc��GMTʱ�� 
  var offset =Number(document.getElementById("city_zone").value); //ʱ��
  var domain_time = utc + (3600000*offset); 
  var nd = new Date(domain_time); 
  document.getElementById("time").innerHTML=nd.toLocaleString();
  setTimeout("startTime()",1000);
}
