//Jeremy Troshynski
//Michelle Gardner
//James Harrison
//CS 303
//Project 1A

#ifndef _ASSIGNMENT_H_
#define _ASSIGNMENT_H_

#include "Date.h"
#include "list.h"
#include "iostream"

using namespace std;

class Assignment
{
private: 
	Date due_date;
	Date assigned_date;
	string description;
	string status;



public:
	Assignment();
	Assignment(Date, string, Date, string); //due_date, description, assigned_date, status
	//~Assignment();

	//setters
	void set_due_date(Date d_date);
	void set_assigned_date(Date a_date);
	void set_description(string descr);
	void set_status(string sta);

	//getters
	Date get_due_date();
	Date get_assigned_date();
	string get_description();
	string get_status();

	bool Assignment::dont_add(list <Assignment> &li, Assignment &A);
	void toString();

	//overloaded operators
	friend ostream& operator << (std::ostream& os, const Assignment& A);
	bool operator ==(const Assignment& other);
	

};

#endif