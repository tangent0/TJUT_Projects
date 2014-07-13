// nochange.js
//   This script illustrates using the focus event
//   to prevent the user from changing a text field

// The event handler function to compute the cost

function computeCost() {
  var book1 = document.getElementById("the_universe").value;
  var book2 = document.getElementById("see_you_pluto").value;
  var book3 = document.getElementById("the_glory_day").value;

// Compute the cost

  document.getElementById("cost").value = 
  totalCost = book1 * 0.01 + book2 * 0.02 + book3 * 0.03;
}  //* end of computeCost




// validator.js
//   An example of input validation using the change and submit events

function myFocus(element) {
   element.focus();
} 

function judge_validator()
{
   if(!chkName())return false; 
   if(!chkPhone())return false;
   alert("Information sending,thank you.");
   return true;
}
   
// The event handler function for the name text box

function chkName() {
  var myName = document.getElementById("custName");

// Test the format of the input name 
//  Allow the spaces after the commas to be optional
//  Allow the period after the initial to be optional

  var pos = myName.value.search(/^[A-Z][a-z]+, ?[A-Z][a-z]+, ?[A-Z][a-z]+\.?$/);

  if (pos != 0) {
    alert("The name you entered (" + myName.value + 
          ") is not in the correct form. \n" +
          "The correct form is: " +
          "last-name, first-name, middle-initial \n" +
          "Please go back and fix your name");
    myFocus(myName);
    myName.select();
    return false;
  } else
    return true;
}

// The event handler function for the phone number text box

function chkPhone() {
  var myPhone = document.getElementById("phone");

// Test the format of the input phone number

  var pos = myPhone.value.search(/^\d{3}-\d{3}-\d{4}$/);

  if (pos != 0) {
    alert("The phone number you entered (" + myPhone.value +
          ") is not in the correct form. \n" +
          "The correct form is: ddd-ddd-dddd \n" +
          "Please go back and fix your phone number");
    myPhone.focus();
    myPhone.select();
    return false;
  } else
    return true;
}

