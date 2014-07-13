// stacking.js
//   Illustrates dynamic stacking of images

var top = "regtext1";

// The event handler function to move teh given element
//  to the top of the display stack

function toTop(newTop) {

// Set the two dom addresses, one for the old top 
//  element and one for the new top element 

  domTop = document.getElementById(top).style;
  domNew = document.getElementById(newTop).style;

// Set the zIndex properties of the two elements, and
//  reset top to the new top

  switch(top){
  case "regtext1": domTop.zIndex = "1"; break;
  case "regtext2": domTop.zIndex = "2"; break;
  case "regtext3": domTop.zIndex = "3"; break;
  case "regtext4": domTop.zIndex = "4"; break;
  case "regtext5": domTop.zIndex = "5"; break;
  case "regtext6": domTop.zIndex = "6"; break;
  case "regtext7": domTop.zIndex = "7"; break;
  case "regtext8": domTop.zIndex = "8"; break;
  }
	  
  domNew.zIndex = "10";
  top = newTop;
}

function toRecover(top){
  domTop = document.getElementById(top).style;
  switch(top){
  case "regtext1": domTop.zIndex = "1"; break;
  case "regtext2": domTop.zIndex = "2"; break;
  case "regtext3": domTop.zIndex = "3"; break;
  case "regtext4": domTop.zIndex = "4"; break;
  case "regtext5": domTop.zIndex = "5"; break;
  case "regtext6": domTop.zIndex = "6"; break;
  case "regtext7": domTop.zIndex = "7"; break;
  case "regtext8": domTop.zIndex = "8"; break;
  }
	  
}

// dynValue.js
//   Illustrates dynamic values
     
var helpers = [
  "This box provides advice on this page. Put the mouse cursor over any picture to get advice.",
  "Mercucy",
  "Venus",
  "Earth",
  "Mars",
  "Jupiter",
  "Saturn",
  "Uranus",
  "Naptune"]

// *********************************************************** 
// The event handler function to change the value of the 
//  textarea

function messages(adviceNumber) {
  document.getElementById("adviceBox").innerHTML = 
                                  helpers[adviceNumber];
}



var startx = 100,starty = 0,finalx = 320, finaly = 0;

function initText() {

var dom = document.getElementById('theText').style;
var x= dom.left;
var y= dom.top,

x = x.match(/\d+/);
y = y.match(/\d+/);

moveText(startx,starty,finalx,finaly);
}

function moveText(x, y,finalx,finaly) {
if (x != finalx)
if (x>finalx) x--;
else if (x<finalx) x++;

if (y != finaly)
if (y>finaly) y--;
else if (y<finaly) y++;

if ((x != finalx) || (y != finaly)) {
var dom = document.getElementById('theText').style;
if((x-startx)%20==0)
  if(dom.color=="blue")dom.color="red"; else dom.color="blue";
dom.left = x + "px";
dom.top = y + "px";
}else {var t=startx; startx=finalx; finalx=t; t=starty; starty=finaly; finaly=t;}
       //swap the coordinares between starting_point and ending_point
 setTimeout("moveText(" + x + "," + y + ","+finalx+","+finaly+")", 10);
                                                                  //10 milliseconds
}



