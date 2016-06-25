
//Jeremy Troshynski
//Michelle Gardner
//James Harrison
//CS 303
//Project 1A

#include "Date.h"
#include "Assignment.h"
#include <list>
#include <iostream>
#include <string>


using namespace std;
Assignment project;
std::list<Assignment> completed = { project };
std::list<Assignment> assigned = { project };




completed.push_front(project);




void print_list(list <Assignment> &list1)
{
	list<Assignment>::const_iterator iter = list1.begin();

	while (iter != list1.end()){
		cout << *iter.get_assigned_date() << endl;
		++iter;
	}
	//iterate through list and print each assignment
};

void add_assignment(list <Assignment> li, Assignment assn)
{
	list<Assignment>::const_iterator iter = list1.begin();

	while (iter->next )
	//add an assignment to the list in the correct position based on assigned_date
	//will need an iterator
	//iterate until current->next assigned_date >= assn assigned_date
	
	//add to the list
	current->next->prev = assn;
	current->next = assn;
};