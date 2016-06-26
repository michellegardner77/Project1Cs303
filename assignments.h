#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <iostream>

using namespace std;

class assignment
{
	private:
		string due_date;
		string description;
		string assigned_date;
		string status;
		static int numOfAssignments;
		bool modified;
		string source_name;
		
	public:
		assignment(); //default constructor
		assignment(string, string, string, string);
		~assignment();
		
		//setters
		void setDueDate(string);
		void setDescription(string);
		void setAssignedDate(string);
		void setStatus(string);
		void add_entry(const assignment& new_assignment);
		void change_entry(const assignment& new_assignment);
		void remove_entry(const std::string& status);
		void lookup_entry(const string& due_date);

		//getters
		string getDueDate()  { return due_date; }
		string getDescription()  { return description; }
		string getAssignedDate()  { return assigned_date; }
		string getStatus()  { return status; }

		static int getNumOfAssignments() { return numOfAssignments; }
		void toString();
		
		
};

#endif