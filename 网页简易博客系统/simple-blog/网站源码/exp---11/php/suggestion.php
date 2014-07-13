<?xml version = "1.0" encoding = "utf-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns = "http://www.w3.org/1999/xhtml">
     <head> <title> suggestion.php </title>
     </head>
<body>
   <p>Your suggestion is as follow,thank you.</p>
   <?php $suggestion=$_POST['suggestion'];?>
   <textarea rows="20" cols="40" overflow="auto">
    <?php
      echo $suggestion;
    ?>
   </textarea>
   <?php
     $user_name=file_get_contents("greeting.txt")or die("Error-file cannot be opened");
     $time=date("h:i A,D,M-j-Y");
     $a_record="\n".$user_name." SENDED AT ".$time.": ".$suggestion."\r\n";

     $filevar=fopen("suggestion.txt",'a')or die("Error - file cannot be openned");
      fwrite($filevar,$a_record);
     fclose($filevar);
     
   ?>
   <?php
    echo "<br />";
    echo "<a href='../index.php'>·µ»Ø</a>";
   ?>
</body>
</html>