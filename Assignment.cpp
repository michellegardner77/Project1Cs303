//Jeremy Troshynski
//Michelle Gardner
//James Harrison
//CS 303
//Project 1A

#include "Assignment.h"
using namespace std;


Assignment::Assignment(){};

Assignment::Assignment(Date assigned_date, Date due_date, string description, enum status)
{
	set_assigned_date(assigned_date);
	set_due_date(due_date);
	set_description(description);
	set_status(status);
}


//setters
void Assignment::set_due_date(Date d_date) //maybe should make this pass in integers to set the date
{
	if (d_date.length() > 1)
		due_date = d_date;
	else {
		cout << "Invalid date format\n" << "Please enter mm-dd-yy" << endl;
		exit(EXIT_FAILURE);
	}
}
void Assignment::set_assigned_date(Date a_date)
{
	if (a_date.length() > 1)
		assigned_date = a_date;
	else {
		cout << "Invalid date format\n" << "Please enter mm/dd/yy" << endl;
		exit(EXIT_FAILURE);
	}
}
void Assignment::set_description(string descr)
{
	if (descr.length() > 1)
		description = descr;
	else {
		cout << "Try again" << endl;
		exit(EXIT_FAILURE);
	}
}

//getters
Date Assignment::get_due_date()
{return due_date;}
Date Assignment::get_assigned_date()
{return assigned_date;}
string Assignment::get_description()
{return description;}

std::ostream& operator << (std::ostream& os, const Assignment& A)
{
	os << A.due_date << ", " << A.description << ", " << A.assigned_date << ", " << endl; //A.status << endl;
	return os;
};

bool Assignment::operator ==(const Assignment& other) {
	return (assigned_date == other.assigned_date);
}



int Assignment::late_assignment(int mL, int dL, int yL, Node list)//for late assignments
{
	int count = 0;
	while (list != nullptr) //using getters that don't exists yet
	{
		count++;
		list = list.getNext(); //'what's the net node'
		if (mL > current_month && dL > current_day) // current_month and day declared in main (maybe)
		{
			//invalidAssignments.pushback //copy the node's info into a late assignment's list
		}
	}
	return 0; //0 for now
}

bool Assignment::dont_add(list <Assignment> &li, Assignment &A) //pass list & assignment to check if that assignment is already in the list
{
	if (A.due_date <= A.assigned_date) // if due_date is less / equal to to assigned_date
	{return false;}

	//if (date != current_date) // if 
	//{return false;}

	list<Assignment>::iterator iter = li.begin();
	while (iter != li.end())
	{
		if ((*iter) == A) //if the assigned date has already been used
			{return false;}
		iter++;
	}
	return true;
}





void Assignment::status(int list, int list1, int list2, int list3)
{
	while (list != nullptr)
	{
		for (int i = 0; i != list.end; i++)
		{
			if (list[i] == "assigned")
			{
				list1.pushback;
			}
		}
		for (int j = 0; j != list.end; j++)
		{
			if (list[j] == "compeleted")
			{
				list2.pushback;
			}
		}
		for (int k = 0; k != list.end; k++)
		{
			if (list[k] == "late")
			{
				list3.pushback;
			}
		}
	}
}