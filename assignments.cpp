#include "assignments.h"

assignment::assignment() {}//default constructor



//int assignment::numOfAssignments = 0;

assignment::assignment(string due_date, string description, string assigned_date, string status ){
	//set values using setters and passing user supplied values
	setDueDate(due_date);
	setDescription(description);
	setAssignedDate(assigned_date);
	setStatus(status);
	//assignment::numOfAssignments++;

}


//setters perform a very basic input validation (needs updated)
//if due date length is correct then consider valid
//these are not good tests
void assignment::setDueDate(string dDate) {
	if (dDate.length() > 1)
		due_date = dDate;
	 else {
		cout << "Invalid date format\n" << "Please enter mm-dd-yy" << endl;
		exit(EXIT_FAILURE);
	}
}
//valid if more than 1 character
void assignment::setDescription(string validDesc) {
	if (validDesc.length() > 1)
		description = validDesc;
	else {
		cout << "Try again" <<  endl;
		exit(EXIT_FAILURE);
	}
}
//if due date length is correct then consider valid
void assignment::setAssignedDate(string validAdate) {
	if (validAdate.length() > 1)
		assigned_date = validAdate;
	else {
		cout << "Invalid date format\n" << "Please enter mm/dd/yy" << endl;
		exit(EXIT_FAILURE);
	}
}

//valid if more than 1 character
void assignment::setStatus(string validStat) {
	if (validStat.length() > 1)
		status = validStat;
	else {
		cout << "Try again" <<  endl;
		exit(EXIT_FAILURE);
	}
}


assignment::~assignment()
{
}




