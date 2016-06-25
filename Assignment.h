//Jeremy Troshynski
//Michelle Gardner
//James Harrison
//CS 303
//Project 1A

#ifndef _ASSIGNMENT_H_
#define _ASSIGNMENT_H_

#include "Date.h"

using namespace std;

class Assignment
{
private: 
	Date due_date;
	Date assigned_date;
	string description;
	enum status; 



public:
	//setters
	void set_due_date(Date d_date);
	void set_assigned_date(Date a_date);
	void set_description(string descr);

	//getters
	Date get_due_date();
	Date get_assigned_date();
	string get_description();
};

#endif