<html>
<body>
   <p>Suggestions are as follow.</p>
   <textarea rows="20" cols="60" overflow="auto">
    <?php
      $suggestions=file_get_contents("suggestion.txt");
      echo $suggestions;
    ?>
   </textarea>
   <?php
     echo "<br />";
     echo "<a href='admin.php'>����</a>";
   ?>
</body>
</html>