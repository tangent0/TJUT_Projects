<html>
<head><title></title>
<script type='text/javascript'>
 var c=3,t;
 function timedCount()
 {
  if(c!=-1)
  {
   document.getElementById('second').innerHTML=c;
   c=c-1;
   t=setTimeout('timedCount()',500)
  }
  else
  {
   clearTimeout(t); alert('logging out succeeded'); 
   location='../index.php'; 
   
   //window.opener=null; window.open('','_self'); window.close();
  }
 }
</script> 
</head>
<body onload="timedCount();">
<?php
  echo "<p>logging,be back in <span id='second'></span> second(s)...</p>";
  $filevar=fopen("admin_login.txt",'w')or die("Error - file cannot be openned");
  fclose($filevar);
  header("Location:../index.php"); //×ªÏò
?>
</body>
</html>