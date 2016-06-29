
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
#include "StringTokenizer.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <limits>
#include <sstream>

using namespace std;
list<Assignment> completed;
list<Assignment> assigned;

void print_list(list <Assignment> &li);
//Displays all assignments in a particular list

void add_assignment(list <Assignment> &li, Assignment assn);
//Adds an assignment to the list

char OnDemand();
/**Menu function that calls everything else
@returns on a switch case
*/

//void displayOutput(vector <Assignment>, int);
//display the output of the .txt file

void myToken();
//string tokenizer that parses by commas

void doPopulate();
//allows the USER interface to populate original assignment.txt file by entering information

void doDisplay();
//displays assignments by type (due date, \ndescription, \nassigned date, \nstatus)

int doCreate();
//creates a very small prepopulated txt file without user input

int doAppend();
//allows for each token to be edited in turn by user input

void doEdit(list <Assignment> &li);

void saveOutput(vector <Assignment>, int);

bool dont_add(list <Assignment> &li, Assignment &A); 
//pass list & assignment to check if that assignment is already in the list



////////////////////////////////////////////////////////////////////////////////////////////////
int main() {



	int temp = 0;
	do {
		doCreate();//creates the txt file if it doesn't already exist
		temp++;
	} while (temp < 1);

	myToken();//initially shows assignments in easy to read format

	OnDemand();//displays menu selections and performs all functions


	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////











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
	
	if (!dont_add(li, assn))
	{
		cout << "Cannot add assignment" << endl;
		return;
	}

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


char OnDemand() {

	int menuOption;
	char repeat = 'Y';
	int number;

	cout << "\n\t\t\t:::::Menu:::::\n" << endl;
	cout << "1 - Display Assignments\t\t4 - Complete Assignment" << endl;
	cout << "2 - Add Assignment\t\t5 - Display Number of Late Assignments" << endl;
	cout << "3 - Edit Assignment\t\t6 - Save" << endl;
	cout << "\t\t\t7 - Exit" << endl;
	while (repeat == 'y' || repeat == 'Y') {
		cout << "\n\nEnter Menu Option " << endl;


		//handles non-integer menu entries
		while (!(cin >> menuOption)) {
			cout << "Must enter an integer value" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}


		switch (menuOption) {
		case 1:
			cout << "\nNow showing the unformatted contents of assignment.txt: " << endl;
			print_list(assigned);

			break;
		case 2:
			cout << "Enter Assignments" << endl;

			//doPopulate();
			doCreate();
			break;
		case 3:
			doEdit(assigned);
			break;
		case 4:
			cout << "Edit Description" << endl;
			//doEditDesc(); //whacked out below
			break;
		case 5:
			cout << "Complete Assignment" << endl;
			//compAssign(); not yet created
			break;
		case 6:
			cout << "Number of Late Assignments" << endl;
			//showNumOfAssign(); not yet created
			break;
		case 7:
			void saveOutput();
			cout << "File assignment.txt saved" << endl;

			//	cout << "\nReturn to Menu? (Y/N)" << endl;
			//	cin >> repeat;

			break;
		case 8:
			return 0;
		default:
			cout << "Invalid Input" << endl;

		}

	}

	return 0;
}



/*void Assignment::toString() {
	cout << "Due date: " << this->due_date << "\nDescription: " << this->description <<
		"/nDate assigned: " << this->assigned_date << "\nAssignment Status: " <<
		this->status << endl;
}
*/

//allows use interface to populate original assignment.txt file
void doPopulate() {
	string due_date;
	string description;
	string assigned_date;
	string status;


	ofstream writer("assignments.txt"); //outputfile sttream--ofstream writer("filename.txt")creates a file if it doesn't alread exist
	if (!writer) { //verifies that the file was created and prints error if not
		cout << "Error OPENING file: " << endl;
		exit(EXIT_FAILURE);
	}
	else { //else if the the file stream is open then you can write to it
		cout << "Enter due date ";
		cin >> due_date;
		writer << due_date << ", "; //-- "\n" is new line allows --writes directly to the file
		cout << "Enter assignment description ";
		cin >> description;
		writer << description << ", "; //-- "\n" is new line allows --writes directly to the file
		cout << "Enter assinged date ";
		cin >> assigned_date;
		writer << assigned_date << ", "; //-- "\n" is new line allows --writes directly to the file
		cout << "Enter assignment status ";
		cin >> status;
		writer << status << endl;
		writer.close(); //closes the file writer



		writer.close(); //closes the file writer
	}

}

void doDisplay(){
	char letter;
	ifstream reader("assignments.txt"); // input file stream reader to read the charachters char letter
	if (!reader) {
		cout << "Error opeNing file: " << endl;
		exit(EXIT_FAILURE);
	}
	else {
		for (int i = 0; !reader.eof(); i++) {//continues reading characters until the reader gets to the eof end of file
			reader.get(letter); //gets the next letter of output we want
			cout << letter;
		}
		cout << endl;
		reader.close();
	}

}


void myToken() { //also outputs assignment file for reading
	//open file for read
	//separates strings by delimiting commas
	ifstream inputFile("assignments.txt");
	//verify file opened
	if (inputFile.fail()) { //verifies that the file was created and prints error if not
		cout << "ERROR opening file: " << endl;
		exit(EXIT_FAILURE);
	}
	else {

		string line;

		vector <Assignment> arrayOfAssignments;
		int counter = 0; // counts the number of entries
		while (getline(inputFile, line)) {
			//split the string by commas 
			//there are 3 commas so the array is declared with 3 indeices that hold the position of each comma
			int commaPos[3];
			int posIndex = 0;
			counter++;


			for (int i = 0; i < line.length(); i++) {

				if (line[i] == ',') {

					commaPos[posIndex] = i;
					posIndex++;

				}
			}

			//now we have the position of the commas so lines can be delimited into 4 separate pieces
			string read_due_date = line.substr(0, commaPos[0]);//starts from 0 goes to first index in commaPos[]

			//need to convert read_due_date to integers from string
			//int day =
			//int month =
			//int year =

			//Assignment assign1(due_date, description, assigned_date, status); //due_date, description, assigned_date, status


			//We will then create the Date object with the separated pieces from read_due_date that have been converted to integers
			//Date due_date(year, month, day);



			string description = line.substr(commaPos[0] + 1, commaPos[1] - commaPos[0] - 1); //description starts from first comma plus 1. length is the 2nd comma position minus 1
			string assigned_date = line.substr(commaPos[1] + 1, commaPos[2] - commaPos[1] - 1);
			string status = line.substr(commaPos[2] + 1);

			//add_assignment(check_status(), assign1);
			//arrayOfAssignments.push_back(Assignment(due_date, description, assigned_date, status));
		}

		inputFile.close();
		//displayOutput(arrayOfAssignments, counter);
	}

}

/* Old print function
void displayOutput(list<Assignment> &li, int count) {

	for (int i = 0; i < li.size(); i++) {
		cout << "Count: " << i + 1 << endl;
		cout << "Due date: " << arrayOfAssignments[i].get_due_date() << endl;
		cout << "Description: " << arrayOfAssignments[i].get_description() << endl;
		cout << "Date assigned: " << arrayOfAssignments[i].get_assigned_date() << endl;
		cout << "Assignment status: " << arrayOfAssignments[i].get_status() << "\n" << endl;
		cout << "------------------------------------------------" << endl;
	}


	//	cout << "Current assignment count: " << assignment::getNumOfAssignments() << endl; //did this another way

}
*/

void doEdit(list <Assignment> &li) { //IN PROGRESS -> Creates a text file, reads in due_date and description, writes to text file
	list<Assignment>::iterator iter = li.begin();
	/*Edit an assignment in the assigned list (e.g. edit 
the due date or the description). 
You first need to find the assignment with the give
n assigned date. 
Don’t edit the assignment in these cases: 
The given assigned or due dates are invalid. */

	string read_assigned_date, read_due_date, read_description;
	//append files
	ofstream writer2("assignments.txt", ios::app);

	if (!writer2) { //verifies that the file was created and prints error if not
		cout << "File doesn't exist" << endl;
		exit(EXIT_FAILURE);
	}
	else { //else if the the file stream is open then you can write to it
		cout << "Enter the assigned date for the assignment you would like to edit (MM-DD-YYYY): " << endl;
		cin >> read_assigned_date;

		bool edited = false;
		while (iter != li.end())
		{
			if ((*iter).get_assigned_date() == read_assigned_date)
			{
				cout << "Enter the new due date (MM-DD-YYYY): " << endl;
				cin >> read_due_date;


				//convert string values to integers
				int month = stoi(read_due_date.substr(0, read_due_date.find("-")));
				cout << "Month: " << month << endl;
				read_due_date.erase(0, (read_due_date.find("-") + 1));

				int day = stoi(read_due_date.substr(0, read_due_date.find("-")));
				cout << "Day: " << day << endl;
				read_due_date.erase(0, (read_due_date.find("-") + 1));

				int year = stoi(read_due_date.substr(0,3));
				cout << "Year: " << year << endl;
				
				//set the new due_date
				Date d_date(year, month, day);
				(*iter).set_due_date(d_date);
				//add piece to check for valid date

				edited = true;
				break;
			}
		}
		if (edited == false)
		{
			cout << "That assignment doesn't exist." << endl;
			return;
		}

		//writer2 << "\n" << read_due_date << endl; //-- "\n" is new line allows --writes to the file 
		//writer2.close(); //closes the file writer
	}

	ofstream writer3("assignments.txt", ios::app);

	if (!writer3) { //verifies that the file was created and prints error if not
		cout << "File doesn't exist" << endl;
		exit(EXIT_FAILURE);
	}
	else { //else if the the file stream is open then you can write to it
		cout << "Enter new description: " << endl;
		cin >> read_description;
		(*iter).set_description(read_description);
		//writer3 << "\n" << read_description << endl; //-- "\n" is new line allows --writes to the file 
		//writer3.close(); //closes the file writer
	}

}

/*
//IN ORDER TO EDIT I WILL NEED THE ABILITY TO FIND OR CHOOSE A PARTICULAR ASSIGNMENT FIRST
//the value due_date will have to be passed into this function from the arrayOf Assignments but haven't figured out how to do that
edit_due_date(){//allows edit due date
ofstream writer1("assignments.txt"); //outputfile sttream--ofstream writer("filename.txt")creates a file if it doesn't alread exist
if (!writer1) { //verifies that the file was created and prints error if not
cout << "Error OPENING file: " << endl;
exit(EXIT_FAILURE);
}
else { //else if the the file stream is open then you can write to it
cout << "Enter new due date " << endl;
cin >> due_date;
writer1 << due_date << "\n " << endl; //-- "\n" is new line allows --writes to the file in string literals
writer1.close(); //closes the file writer
}

}
*/

int doCreate() {

	string popul1 = "2-11-2015, linked lists, 2-2-2015, late";
	string popul2 = "3-10-2015, stacks, 3-1-2015, assigned";
	string popul3 = "12-31-2015, queues, 12-20-2015, completed";

	Assignment A((Date(2014, 12, 12)), "this is the description1", (Date (2014, 12, 13)), "cancelled1");
	Assignment B((Date(2015, 12, 12)), "this is the description2", (Date(2015, 12, 13)), "cancelled2");
	Assignment C((Date(2016, 12, 12)), "this is the description3", (Date(2016, 12, 13)), "cancelled3");

	ofstream writer("assignments.txt"); //outputfile sttream--ofstream writer("filename.txt")creates a file if it doesn't alread exist
	if (!writer) { //verifies that the file was created and prints error if not
		cout << "Error opening file: " << endl;
		return -1; //signals error
	}
	else { //else if the the file stream is open then you can write to it
		writer << popul1 << endl; //allows writes to the file
		writer << popul2 << endl;
		writer << popul3 << endl;
		writer.close(); //closes the file writer
	}
}

int doAppend(){
	string due_date;
	string description;
	string assigned_date;
	string status;
	string edit_date;

	ofstream writer2("assignments.txt", ios::app);
	//ios::app -- open a stream to append what is there 
	//ios::binary -- Treat the file as binary
	// ios::trunc -- default
	//ios::out -- Open a file to write output
	//ios::in  -- Open a file to write an input

	if (!writer2) { //verifies that the file was created and prints error if not
		cout << "Error opening file: " << endl;
		return -1; //signals error
	}
	else { //else if the the file stream is open then you can write to it
		cout << "Enter due date ";
		cin >> due_date;
		writer2 << due_date << ", "; //-- "\n" is new line allows --writes directly to the file
		cout << "Enter assignment description ";
		cin >> description;
		writer2 << description << ", "; //-- "\n" is new line allows --writes directly to the file
		cout << "Enter assinged date ";
		cin >> assigned_date;
		writer2 << assigned_date << ", "; //-- "\n" is new line allows --writes directly to the file
		cout << "Enter assignment status ";
		cin >> status;
		writer2 << status;
		writer2.close(); //closes the file writer
	}
}


void saveOutput(vector<Assignment> arrayOfAssignments, int count) {
	for (int i = 0; i < arrayOfAssignments.size(); i++) {
		cout << "Count: " << i + 1 << endl;
		cout << "Due date: " << arrayOfAssignments[i].get_due_date() << ", ";
		cout << "Description: " << arrayOfAssignments[i].get_description() << ", ";
		cout << "Date assigned: " << arrayOfAssignments[i].get_assigned_date() << ", ";
		//cout << "Assignment status: " << arrayOfAssignments[i].get_status() << "\n" << endl;
		cout << "------------------------------------------------" << endl;
	}
}


bool dont_add(list <Assignment> &li, Assignment &A) //pass list & assignment to check if that assignment is already in the list
{
	if (A.get_due_date() <= A.get_assigned_date()) // if due_date is less / equal to assigned_date
	{
		return false;
	}

	list<Assignment>::iterator iter = li.begin();
	while (iter != li.end())
	{
		if ((*iter) == A) //if the assigned date has already been used
		{
			return false;
		}
		iter++;
	}
	return true;
}