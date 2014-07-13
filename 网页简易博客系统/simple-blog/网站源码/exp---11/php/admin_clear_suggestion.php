<html>
<body>
<strong>The content in suggestion.txt has been cleared.</strong><br />
<?php

  $filevar=fopen("suggestion.txt",'w')or die("Error - file cannot be openned");
  fclose($filevar);
  
  echo "<br />";
  echo "<a href='admin.php'>·µ»Ø</a>";
?>
</body>
</html>
