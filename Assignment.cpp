//Jeremy Troshynski
//Michelle Gardner
//James Harrison
//CS 303
//Project 1A

#include "Assignment.h"
using namespace std;

//setters
void Assignment::set_due_date(Date d_date)
{due_date = d_date;}
void Assignment::set_assigned_date(Date a_date)
{assigned_date = a_date;}
void Assignment::set_description(string descr)
{description = descr;}

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

bool Assignment::dont_add(list <Assignment> &li, Assignment &A) //pass list & assignment to check if that assignment is already in the list
{
	if (A.due_date <= A.assigned_date) // if due_date is less / equal to to assigned_date
	{return false;}

	//if (date != current_date) // I wasn't sure what this function was supposed to do
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
