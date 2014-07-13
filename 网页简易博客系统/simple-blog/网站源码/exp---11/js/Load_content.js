function Load_content(value)
{
 switch(value)
  {
   case 0: document.getElementById("content").innerHTML="<iframe src='js/html/home_page.html'width='100%' height='100%' allowTransparency='true' frameborder='0' scrolling='no'></iframe>";       
           break;
   case 1: document.getElementById("content").innerHTML="<iframe src='js/html/Upload-some-pictures.html'width='100%' height='100%' allowTransparency='true'frameborder='0' scrolling='no'></iframe>";
	    break;
   case 2: document.getElementById("content").innerHTML="<iframe src='js/html/order_some_books.html'width='100%' height='100%' allowTransparency='true' frameborder='0' scrolling='no'></iframe>";
	    break;
   case 3: document.getElementById("content").innerHTML="<iframe src='js/html/see_some_planets.html'width='100%' height='100%' allowTransparency='true' frameborder='0' scrolling='no'></iframe>";
           break;
  }
  for(var i=0;i<document.getElementsByName("menu_ul_load_content").length;i++)
    if(i==value)
     {
       document.getElementsByName("menu_ul_load_content")[i].firstChild.style.backgroundColor="#693";          
       document.getElementsByName("menu_ul_load_content")[i].firstChild.style.color="red";
       document.getElementsByName("menu_ul_load_content")[i].firstChild.style.textDecoration="underline";}
     else 
     {
       document.getElementsByName("menu_ul_load_content")[i].firstChild.style.backgroundColor="purple";
       document.getElementsByName("menu_ul_load_content")[i].firstChild.style.color="white";
       document.getElementsByName("menu_ul_load_content")[i].firstChild.style.textDecoration="none";
     }
}
