
//Jeremy Troshynski
//Michelle Gardner
//James Harrison
//CS 303
//Project 1A

#include "Date.h"
#include "Assignment.h"
#include "list.h"
#include "list_iterator.h"
#include "Ordered_list.h"
#include <list>
#include <iostream>
#include <string>


using namespace std;
list<Assignment> completed;
list<Assignment> assigned;


//iterate through list and print each assignment
void print_list(list <Assignment> &li)
{
	list<Assignment>::iterator iter = li.begin();

	while (iter != li.end()){
		cout << (*iter) << endl;
		++iter;
	}
};



void add_assignment(list <Assignment> &li, Assignment assn)
{
	list<Assignment>::iterator iter = li.begin();
	
	if (li.empty()) //empty list
	{
		li.push_front(assn);
	};
	
	while (iter != li.end()) //iterate until the end
	{
		if ((*iter).get_assigned_date() > assn.get_assigned_date()) //if correct position
		{
			li.insert(iter, assn);
			break;
		}
		iter++;
	};
};
