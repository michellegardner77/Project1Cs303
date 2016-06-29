
///All of this code was Michelle's that might not have gotten implemented



/*

bool late_assignment(list <Assignment> &li, Assignment &A) //for late assignments
{

	list iter = li.begin();
	while (iter != li.end())
	{
		if (A.due_date <= A.assigned_date) // I am assuming I'm reading in lists and finding the late assignments
		{
			return false;
			if (A.due_date > A.assigned_date)
			{
				late_assignments.pushback(); //Want to add the late assignment to a list of its' own
				return true;
			}
			iter++;
		}
	}
}


int Assignment::count_LA(list <Assignment> &li, Assignment &A)
{

	int countLA = 0;
	list<Assignment>::iterator itr = li.begin(); // Do I need to state this every time I need to loop through a list?
	while (itr != li.end)
	{
		countLA++;
	}
	return countLA;
}

string Assignment::dont_complete(list <Assignment> &li, Assignment &A)
{

	list<Assignment>::iterator iter = li.begin();
	while (iter != nullptr)
	{
		for (int i = 0; i != li.end; i++)
		{
			if (A != li[i]) //check to see if read in assignment is already in "assigned list"
			{
				cout << "Don't complete." << endl; //don't complete the assignment
			}

			if (date >= current_date || date <= current_date || completetion_date != current_date) //change vars
				//don't complete if the given assigned or completions dates are invalid. 
			{
				cout << "Don't complete." << endl;
			}
		}

	}
}

void Assignment::status(list <Assignment> &li, Assignment &A)
{
	list<Assignment>::iterator iter = li.begin();
	while (iter != nullptr)
	{
		for (int i = 0; i != li.end; i++) //what I wanted to do was push back "assigned" assignments into an "assigned list"
		{
			if (li[i] == "assigned") //should probably check dates to make sure assigned
			{
				li.pushback;
			}
		}
		for (int j = 0; j != li.end; j++) //should probably check dates to make sure completed
		{
			if (li[j] == "completed")
			{
				li.pushback;
			}
		}
		for (int k = 0; k != li.end; k++) //should probably check dates to make sure late
		{
			if (li[k] == "late")
			{
				li.pushback;
			}
		}
	}



	//The Status. The direcctions ask for late, completed, and assigned

	list Assignment::status(list <Assignment> &late, Assignment &A, list <Assignment> &assigned, Assignment &A, list <Assignment> &completed)
	{
		list<Assignment>::iterator iter = li.begin();
		while (iter != nullptr)
		{
			for (int i = 0; i != li.end; i++)
			{
				if (A.due_date <= A.assigned_date)
				{
					if (li[i] == "assigned")
					{
						return assigned;
					}
				}

				for (int j = 0; j != li.end; j++)
				{
					if (A.due_date <= A.assigned_date)
					{
						if (li[j] == "completed")
						{
							return completed;
						}
					}

				}

				for (int k = 0; k != li.end; k++)
				{
					if (A.due_date >= A.assigned_date)
					{
						if (li[k] == "late")
						{
							return late;
						}
					}
				}


			}
		}
	}

	//Count Late Assignments
int Assignment::count_LA(list <Assignment> &li, Assignment &A)
{
	int countLA = 0;
	list<Assignment>::iterator itr = li.begin();
	while (itr != li.end)
	{
		if ((*itr).status = "late")
		{
			countLA++;
		}
	}
	return countLA;
}

*/