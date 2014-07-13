function judge(){

 if(document.forms[0].name.value==""){
   alert("Please Input your name");
   document.forms[0].name.focus();
   return false;
 }



 if(document.forms[0].pwd.value==""){
   alert("Please Input your pwd");
   document.forms[0].pwd.focus();
   document.forms[0].pwd.select();
   return false;
 } 
 if(document.forms[0].confirm.value==""){
   alert("Please Input your confirm pwd");
   document.forms[0].confirm.focus();
   document.forms[0].confirm.select();
   return false;
 } 
 if(document.forms[0].pwd.value!=document.forms[0].confirm.value){     
   alert("The passwords are not the same,please input both again");
   document.forms[0].pwd.focus();
   document.forms[0].pwd.select();
   return false;
 }



 if(document.forms[0].age.value==""){
   alert("Please Input your age");
   document.forms[0].age.focus();
   return false;
 } 
 for(var i=0;i<document.forms[0].age.length;i++){
    var c=document.forms[0].age.charAt(i);
    if(c<"0"||c>"9"){
     alert("Age should be all integer");
     document.forms[0].name.focus();
     document.forms[0].name.select();
     return false;
    }
 }
 var ageValue=parseInt(document.forms[0].age.value);
 if(ageValue<10){     
   alert("You can't be So young");
   document.forms[0].age.focus();
   document.forms[0].age.select();
   return false;
 }
 if(ageValue>150){     
   alert("You can't be So old");
   document.forms[0].age.focus();
   document.forms[0].age.select();
   return false;
 }



 pos=document.forms[0].email.value.search("@");
 if(pos==-1){     
   alert("Please Input the correct email address");
   document.forms[0].email.focus();
   document.forms[0].email.select();
   return false;
 }
 alert("Information sending,thank you");

 getElementById("content").innerHTML="";
 return true;
 }

