<?xml version = "1.0" encoding = "utf-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns = "http://www.w3.org/1999/xhtml">
     <head> <title> order.php </title>
     </head>

<body>
    <p>your order is as follow,thank you.</p>
    <?php
      $custName = $_POST['custName'];
      $phone = $_POST['phone']; 
	  $book1 = $_POST['the_universe'];
      $book2 = $_POST['see_you_pluto'];
      $book3 = $_POST['the_glory_day'];
	  $cost = 0.01*$book1+0.02*$book2+0.03*$book3;
	?>
      <h3> Book Order Form </h3>	  
	  <table border="border">
           <tr><th> custName </th><td><?php echo $custName ?></td> </tr>
           <tr><th> phone </th><td><?php echo $phone ?></td> </tr>
	  </table>
      <hr />
      <table border = "border">
        <tr><th> Product Name </th><th> Price </th> <th> Quantity </th></tr>
          <!-- Now, the table data entries -->
        <tr><th> the_universe </th><td> 0.01 RMB</td><td><?php echo $book1 ?></td> </tr>
        <tr><th> see_you,pluto </th><td> 0.02 RMB </td><td><?php echo $book2 ?></td> </tr> 
        <tr><th> the_glory_day </th><td> 0.03 RMB </td><td><?php echo $book3 ?></td> </tr>
        <tr><th> total cost: </th><td colspan="2"><?php echo "$cost RMB"?></td> </tr>

  </body>
</html>
