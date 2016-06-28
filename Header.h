bool Assignment::dont_add(list <Assignment> &li, Assignment &A) //pass list & assignment to check if that assignment is already in the list
{
	if (A.due_date <= A.assigned_date) // if due_date is less / equal to assigned_date
	{
		return false;
	}

	//if (date != current_date) // I wasn't sure what this function was supposed to do
	//{return false;}

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
bool Assignment::late_assignment(list <Assignment> &li, Assignment &A) //for late assignments
{

	list iter = li.begin();
	while (iter != li.end())
	{
		if (A.due_date >= A.assigned_date) // I am assuming I'm reading in lists and finding the late assignments
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


int Assignment::count_LA(list <Assignment> &li, Assignment &A) //count late assignments
{

	int countLA = 0;
	list<Assignment>::iterator itr = li.begin(); // Do I need to state this every time I need to loop through a list?
	while (itr != li.end)
	{
		if ((*itr).status == "late")
		{
			LA++
		}
	}
	return countLA;
}

string Assignment::dont_complete(list <Assignment> &li, Assignment &A) //if an assignment is not on the assigned list, and you're trying to complete it. 
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

void Assignment::status(list <Assignment> &li, Assignment &A)  //
{
	list<Assignment>::iterator iter = li.begin();
	while (iter != nullptr)
	{
		for (int i = 0; i != li.end; i++) //what I wanted to do was push back "assigned" assignments into an "assigned list"
		{
			if (li[i] == "assigned")
			{
				li.pushback;
			}
		}
		for (int j = 0; j != li.end; j++)
		{
			if (li[j] == "completed")
			{
				li.pushback;
			}
		}
		for (int k = 0; k != li.end; k++)
		{
			if (li[k] == "late")
			{
				li.pushback;
			}
		}
	}