function createCaption()
{
  var x=document.getElementById('myTable').createCaption();
  x.innerHTML="�ҵ�ͼƬ��� <input type='button' onclick='createCaption()' value='��������'>";
}
//

//
function insertRow(r)
{
 var i=r.parentNode.parentNode.rowIndex;
 
 var clen=document.getElementById('myTable').rows[i].cells.length;
 
 var x=document.getElementById('myTable').insertRow(i);
 for(var j=0; j < clen-1; j++)
 {
  y=x.insertCell(j);
  y.innerHTML='<br /> <br /> <br /> <br />'+
              ' <input type="button" onclick="chgCont(this)" value="�ı�����"> '+
              ' <input type="button" onclick="insCell(this)" value="���뵥Ԫ"> '+
			  ' <input type="button" onclick="delCell(this)" value="ɾ����Ԫ">';
 }

  y=x.insertCell(j);
  y.innerHTML='<input type="button" onclick="insertRow(this)" value="������"> <input type="button" onclick="deleteRow(this)" value="ɾ����">';
}
function deleteRow(r)
{
 var i=r.parentNode.parentNode.rowIndex;
 document.getElementById('myTable').deleteRow(i);
}

/*insert delete or change*/
function ask_for_a_path()
{
 var pic_path = prompt("input the path of the new picture:","");
 if(pic_path!=null&&pic_path!="")
 {

 if(pic_path.search(/^..\/..\//) <= 0) pic_path='../../'+pic_path;

 var pic_name=pic_path.match(/\/[^\/]*$/);

 x.innerHTML=' <img src=\"'+ pic_path + '\"'+'alt=\"' + pic_path + '\"/> <br />'+ 
	         pic_name + ' <br />'+
             ' <input type="button" onclick="chgCont(this)" value="�ı�����"> '+
             ' <input type="button" onclick="insCell(this)" value="���뵥Ԫ"> '+
			 ' <input type="button" onclick="delCell(this)" value="ɾ����Ԫ">';
 }
 else
 {
   x.innerHTML='<br /> <br /> <br /> <br />'+
             ' <input type="button" onclick="chgCont(this)" value="�ı�����"> '+
             ' <input type="button" onclick="insCell(this)" value="���뵥Ԫ"> '+
			 ' <input type="button" onclick="delCell(this)" value="ɾ����Ԫ">';
 }
 
}
function chgCont(r)
{
 var i=r.parentNode.parentNode.rowIndex;
 var j=r.parentNode.cellIndex;

 x=document.getElementById('myTable').rows[i].cells[j];
 ask_for_a_path();
}
function insCell(r)
{
 var i=r.parentNode.parentNode.rowIndex;
 var j=r.parentNode.cellIndex;

 x=document.getElementById('myTable').rows[i].insertCell(j);
 ask_for_a_path();
}
function delCell(r)
{
 var i=r.parentNode.parentNode.rowIndex;
 var j=r.parentNode.cellIndex;

 x=document.getElementById('myTable').rows[i].deleteCell(j);

}

//
function ChgCaption()
{
  var x=document.getElementById("mySelect");
  var i=document.getElementById("mySelect").selectedIndex;

  document.getElementById("caption").innerHTML=x.options[i].text;
}