
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
Assignment project;
list<Assignment> completed;
list<Assignment> assigned;




completed.push_front(project);



//iterate through list and print each assignment
void print_list(list <Assignment> &li)
{
	list<Assignment>::iterator iter = li.begin();

	while (iter != li.end()){
		cout << *iter.get_due_date() << ", " << *iter.get_description() << ", " << *iter.get_assigned_date() << ", " << *iter.get_status() << endl;
		++iter;
	}
};



void add_assignment(list <Assignment> &li, Assignment assn)
{
	list<Assignment>::iterator iter = li.begin();
	
	if (li.is_empty()) //empty list
	{

	}
	
	while (iter != li.end()) //iterate until correct position
	{
		if (iter.get_assigned_date() > assn.get_assigned_date()) //if correct position
		{
			li.insert(iter, assn);
			break;
		}
		iter++;
	};
	Assignment* newassign = new Assignment;
	newassign = assn;
	*iter->next->prev = assn; //add to the list
	current->next = assn;
	//iterate until current->next assigned_date >= assn assigned_date
	
};
