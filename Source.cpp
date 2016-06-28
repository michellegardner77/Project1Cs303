

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<iomanip>

#include "assignments.h"
#include "String_Tokenizer.h"
//#include "Date.h"

#include <istream>
#include <ostream>
#include <limits>

//prototypes
char OnDemand();
/**Menu function that calls everything else
@returns on a switch case
*/
void displayOutput(vector <assignment>, int);
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

void saveOutput(vector <assignment>, int);
//saves changes and returns to menu selection

//void find(vector<assignment>, int);

//void edit_due_date(string*);



using namespace std;

//char menu();
//int file_create();



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

char OnDemand() {

	int menuOption;
	char repeat = 'Y';
	int number;

	cout << "\n\t\t\t:::::Menu:::::\n" << endl;
	cout << "1 - Display Assignments\t\t5 - Complete Assignment" << endl;
	cout << "2 - Add Assignment\t\t6 - Display Number of Late Assignments" << endl;
	cout << "3 - Edit Due Date\t\t7 - Save" << endl;
	cout << "4 - Edit Description\t\t8 - Exit" << endl;
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
			doDisplay();
			break;
		case 2:
			cout << "Enter Assignments" << endl;

			//doPopulate();
			doCreate();
			break;
		case 3:
			cout << "Enter date of the assignment you would like to edit" << endl;
			//find();
			//doeditDueDate(); //function is below still needs work to pass in correct delimitted position
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



void assignment::toString() {
	cout << "Due date: " << this->due_date << "\nDescription: " << this->description <<
		"/nDate assigned: " << this->assigned_date << "\nAssignment Status: " << 
		this->status << endl;
}


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

		vector <assignment> arrayOfAssignments;
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
			string due_date = line.substr(0, commaPos[0]);//starts from 0 goes to first index in commaPos[]
			string description = line.substr(commaPos[0] + 1, commaPos[1] - commaPos[0] - 1); //description starts from first comma plus 1. length is the 2nd comma position minus 1

			string assigned_date = line.substr(commaPos[1] + 1, commaPos[2] - commaPos[1] - 1);
			string status = line.substr(commaPos[2] + 1);
			arrayOfAssignments.push_back(assignment(due_date, description, assigned_date, status));
		}

		inputFile.close();
		displayOutput(arrayOfAssignments, counter);
	}

}

	void displayOutput(vector<assignment> arrayOfAssignments, int count) {
		for (int i = 0; i < arrayOfAssignments.size(); i++) {
			cout << "Count: " << i + 1 << endl;
			cout << "Due date: " << arrayOfAssignments[i].getDueDate() << endl;
			cout << "Description: " << arrayOfAssignments[i].getDescription() << endl;
			cout << "Date assigned: " << arrayOfAssignments[i].getAssignedDate() << endl;
			cout << "Assignment status: " << arrayOfAssignments[i].getStatus() << "\n" << endl;
			cout << "------------------------------------------------" << endl;
		}

		
//	cout << "Current assignment count: " << assignment::getNumOfAssignments() << endl; //did this another way

}


void doEditDesc() { //
					//IN ORDER TO EDIT I WILL NEED THE ABILITY TO FIND OR CHOOSE A PARTICULAR ASSIGNMENT FIRST and I have had no luck

	string due_date, description;
	//append files
	ofstream writer2("assignments.txt", ios::app);
	//ios::app -- open a stream to append what is there 
	//ios::binary -- Treat the file as binary
	// ios::trunc -- default this is what is is if you don't assign it
	//ios::out -- Open a file to write output

	if (!writer2) { //verifies that the file was created and prints error if not
		cout << "File doesn't exist" << endl;
		exit(EXIT_FAILURE);
	}
	else { //else if the the file stream is open then you can write to it
		cout << "Enter append due date: " << endl;
		cin >> due_date;
		writer2 << "\n" << due_date << endl; //-- "\n" is new line allows --writes to the file 
		writer2.close(); //closes the file writer
	}

	ofstream writer3("assignments.txt", ios::app);

	if (!writer3) { //verifies that the file was created and prints error if not
		cout << "File doesn't exist" << endl;
		exit(EXIT_FAILURE);
	}
	else { //else if the the file stream is open then you can write to it
		cout << "Enter new description: " << endl;
		cin >> description;
		writer3 << "\n" << description << endl; //-- "\n" is new line allows --writes to the file 
		writer3.close(); //closes the file writer
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


void saveOutput(vector<assignment> arrayOfAssignments, int count) {
	for (int i = 0; i < arrayOfAssignments.size(); i++) {
		cout << "Count: " << i + 1 << endl;
		cout << "Due date: " << arrayOfAssignments[i].getDueDate() << ", ";
		cout << "Description: " << arrayOfAssignments[i].getDescription() << ", ";
		cout << "Date assigned: " << arrayOfAssignments[i].getAssignedDate() << ", ";
		cout << "Assignment status: " << arrayOfAssignments[i].getStatus() << "\n" << endl;
		cout << "------------------------------------------------" << endl;
	}
}



/**JUNK--non working template
void find(vector<assignment> arrayOfAssignments, int i)
{
string date;
cin >> date;
for (int i = 0; i < arrayOfAssignments.size(); i++) {
if (arrayOfAssignments[i].getAssignedDate() == date)

return i;//returns the index where the date is found
cout << "Enter new due date: " << endl;
}
exit(EXIT_FAILURE);
}
*/



/* JUNK--non working template
//search the array for the given status
void lookup_entry(const string& due_date)
{
int index = find(due_date);
if (index != -1) {
return arrayOfAssignments[index];
}
else {
return assignment();
}
}
*/


/*JUNK--non working template
remove_entry(const string& status){
int index = find(status);
if (index == -1 )
return;

assignments.erase(index);

modified = true;
}*/


	




