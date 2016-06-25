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


