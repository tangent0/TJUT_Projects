<?xml version = "1.0" encoding = "utf-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns = "http://www.w3.org/1999/xhtml">
<head><title>upload_file.php</title>
</head>
<body>

<?php

 if (($_FILES["file"]["type"] == "image/gif")
 || ($_FILES["file"]["type"] == "image/jpeg")
 || ($_FILES["file"]["type"] == "image/pjpeg")
 && ($_FILES["file"]["size"] < 100000))
   {
   if ($_FILES["file"]["error"] > 0)
     {
     echo "Return Code: " . $_FILES["file"]["error"] . "<br />";
     }
   else
     {
     if (file_exists("upload/" . $_FILES["file"]["name"]))
       {
       echo "<b>";       
       echo "sorry<br/>";
       echo $_FILES["file"]["name"] . " already exists. ";
       echo "</b>";
       }
     else
       {      
      echo "<b>";
      echo "the Information of your sended files are as follow<br />";
      echo "<table border='border'>";
      echo "<tr><th>Upload:</th><td>" . $_FILES["file"]["name"]. "</td></tr>";
      echo "<th>Type:</th><td>" . $_FILES["file"]["type"] . "</td></tr>";
      echo "<th>Size:</th><td>" . "(". ($_FILES["file"]["size"] / 1024) . ")KB.". "</td></tr>";
      echo "<th>Temp file:</th><td>" . $_FILES["file"]["tmp_name"]. "</td></tr>";
      echo "</table>";
      echo "</b>";

	  echo "<strong>";
       move_uploaded_file($_FILES["file"]["tmp_name"] , "upload/" . $_FILES["file"]["name"]);
       echo "Stored in: " . "php/upload/" . $_FILES["file"]["name"];
      echo "</strong>";

      echo "<br /><br />";
      $destination = 'upload/'.$_FILES['file']['name'];
	  echo "<strong>Õº∆¨‘§¿¿£∫</strong> <br />";
	  echo "<img src=\"{$destination}\" alt=\"{$_FILES['file']['name']}\" />";  
       }
     }
   }
 else
   {
   echo "Invalid file";
   }

 ?>

</body>

</html>