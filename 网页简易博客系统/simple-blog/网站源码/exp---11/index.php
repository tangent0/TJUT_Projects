<?xml version = "1.0" encoding="utf-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head><title> my_home_page </title>
  <meta name="Generator" content="EditPlus" />
  <meta name="Author" content="" />
  <meta name="Keywords" content="" />
  <meta name="Description" content="" />

  <link rel="stylesheet" type="text/css" href="css/layout.css"/>
  <script type="text/javascript" src="js/Clock_time.js"></script>
  <script type="text/javascript" src="js/Load_content.js"></script>
</head>

<body onload="startTime();javascript:Load_content(0);">
     <div id="container">
         <div id="header">
		     <img src="css/images/header.jpg"alt="the_moon" />
             <marquee>
	             <span>Welcome to my_home_page,help yourself...</span>
			 </marquee>
         </div>

         <div id="menu">
             <ul>       
               <?php    
			       $filevar=fopen("php\greeting.txt","r")or die("Error - file cannot be openned");
                   flock($filevar,3);
	               $name=file_get_contents("php/greeting.txt");
	               if(!empty($name)){
               ?>
                <li name="menu_ul_load_content" class="rtl"><a onclick="javascript:Load_content(0);">Home-page</a></li>
                <li name="menu_ul_load_content" class="rtl"><a onclick="javascript:Load_content(1);">Upload-some-pictures</a></li>
                <li name="menu_ul_load_content" class="rtl"><a onclick="javascript:Load_content(2);">Order-some-books</a></li>
                <li name="menu_ul_load_content" class="rtl"><a onclick="javascript:Load_content(3);">See-some-planets</a></li>
             	<?php           
                   }else echo "<strong>hello,guest,<br />please regist or login</strong>";
			       flock($filevar,1);
                   fclose($filevar);
                ?>    
             </ul> 
         </div>

         <div id="mainContent"> 
             <div id="sidebar">
			     <div id="welcome">
                     <?php    
					      $filevar=fopen("php/greeting.txt","r")or die("Error - file cannot be openned");
						  flock($filevar,3);
	                      $name=file_get_contents("php/greeting.txt");
	                      if(!empty($name))echo "<strong>welcome,$name</strong>"; else echo "<strong>hello,guest,<br />please regist or login</strong>";
						  flock($filevar,1);
	                      fclose($filevar);
					 ?>
	             </div>
			     <hr />
	             <div id="sidebar_form">
                     <form method="post" action="" onsubmit="" id="index_form1">
                          <span>user Login or Regist </span> <br />
                          <table>   
                                <tr><td>username:</td><td colspan="4"><input type="text" id="username" name="username" value="tom"/>   </td></tr> 
                                <tr><td>password:</td><td colspan="4"><input type="password" id="pwd" name="pwd" value="tom"/></td></tr>
	                            <tr>                                   
								    <td><input type="reset"value="Reset" /></td>
								    <td><input type="submit"value="Login" onclick="javascript:getElementById('index_form1').action='php/login.php';"/></td>
                                    <td><input type="submit"value="Logout" onclick="javascript:getElementById('index_form1').action='php/logout.php';"/></td>
	                                <td><input type="button"value="Regist" onclick="javascript:Load_content(0);" /></td>
	                            </tr>                                    
                          </table>
                     </form>
					 <hr />
                     <form method="post" action="" onsubmit="" id="index_form2">
					      <span>admin Login</span> <br />
					      <table>
                                <tr>
								    <td>admin:</td>
								    <td colspan="4"><input type="text" id="admin" name="admin" value="admin"/> </td>
								</tr> 
                                <tr> 
								    <td>password:</td>
								    <td colspan="4"><input type="password" id="pwd" name="pwd" value="admin"/> </td>
								</tr>
								<tr>
								    <td><input type="reset" value="Reset" /></td>
								    <td><input type="submit" value="Admin login" onclick="javascript:getElementById('index_form2').action='php/admin_login.php';"/></td>
								    <td><input type="submit" value="Admin logout" onclick="javascript:getElementById('index_form2').action='php/admin_logout.php';"/><td>
								</tr>
						  </table>
                     </form>
	             </div>
                 <hr />
                 <div id="sidebar_time">
		             <div id="time"></div>
                     <select id="city_zone" size="1"> 
                            <option value="8" selected="selected">Local time</option>
                            <option value="8">Beijing time</option> 
                            <option value="0">London time</option>
                            <option value="9">Tokyo time</option>
	                        <option value="-5">New York time</option>
                     </select>  
	             </div>
                    <hr />
                 <div id="sidebar_suggestion">
				     <form id="suggestion" action="" method="post">
                     <span>any suggestion? </span><br />
					 <span>write below... and tell me...</span><br />
                     <textarea name="suggestion" rows="15" cols="35" overflow="auto" >(be concise and concret)</textarea>
                     <br />
                     <input type="submit" value="submit" onclick="alert('suggestion sending,thank you.'); getElementById('suggestion').action='php/suggestion.php';"/>
                     <input type="reset" value="reset" />
					 </form>
                 </div>
                 <hr />
				 <div id="sidebar_validation">
                 <p>
                   <a href="http://validator.w3.org/check?uri=referer">
                     <img src="http://www.w3.org/Icons/valid-xhtml10" alt="Valid XHTML 1.0 Strict" height="31" width="88" />
                   </a>
                    <a href="http://jigsaw.w3.org/css-validator/check/referer">
                      <img style="border:0;width:88px;height:31px"src="http://jigsaw.w3.org/css-validator/images/vcss-blue"alt="Valid CSS!" />
                    </a>
                 </p>
				 </div>
                 <hr />
             </div>
             <div id="content"></div>
         </div>

         <div id="footer">
             <marquee>
				     <span>Welcome to my home page...er...copyright for free...</span>
		     </marquee>
         </div>
     </div>
</body>
</html>
