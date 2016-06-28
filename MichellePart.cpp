iint Assignment::assignment_date(int m, int d, int y); //to set date (maybe)
{
	month = m;
	day = d;
	year = y;
}

bool Assignment::late_assignment(list <Assignment> &li ,Assignment &A)//for late assignments
{
	}
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
	bool Assignment::dont_add(list <Assignment> &li, Assignment &A) //pass list & assignment to check if that assignment is already in the list
{
	if (A.due_date <= A.assigned_date) // if due_date is less / equal to to assigned_date
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


int Assignment::count_LA(list <Assignment> &li, Assignment &A)
{

	int countLA = 0;
	list<Assignment>::iterator itr = li.begin(); // Do I need to state this every time I need to loop through a list?
	while (iter != li.end)
	{
		countLA++;
	}
	return countLA;
}

char Assignment::dont_complete(list <Assignment> &li, Assignment &A) 
{//i am assuming there are already lists made for late, wip and assigned
	list<assignment>::iterator iter = li.begin();
	while (iter != nullptr)
	{
		for (int i = 0; i != list1.end; i++)
		{
			if (listItem != list1[i])
			{
				cout << "Don't complete." << endl;
			}
			if (listItem != list2[i])
			{
				cout << "Don't complete." << endl;
			}
			if (listItem != list3[i])
			{
				cout << "Don't complete." << endl;
			}
			if (date >= current_date || date <= current_date || completetion_date != current_date)
			{
				cout << "Don't complete." << endl;
			}
		}

	}
}

void Assignment::status(list <Assignment> &li, Assignment &A)
{
	list<assignment>::iterator iter = li.begin();
	while (iter!= nullptr)
	{
		for (int i = 0; i != list.end; i++)
		{
			if (list[i] == "assigned")
			{
				list1.pushback;
			}
		}
		for (int j = 0; j != list.end; j++)
		{
			if (list[j] == "compeleted")
			{
				list2.pushback;
			}
		}
		for (int k = 0; k != list.end; k++)
		{
			if (list[k] == "late")
			{
				list3.pushback;
			}
		}
	}
