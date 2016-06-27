int Assignment::assignment_date(int m, int d, int y); //to set date (maybe)
{
	month = m;
	day = d;
	year = y;
}

int Assignment::late_assignment(int mL, int dL, int yL, Node list)//for late assignments
{
	int count = 0;
	while (list != nullptr) //using getters that don't exists yet
	{ 
		count++;
		list = list.getNext(); //'what's the net node'
		if (mL > current_month && dL > current_day) // current_month and day declared in main (maybe)
			{
				//invalidAssignments.pushback //copy the node's info into a late assignment's list
			}
	}
	return 0; //0 for now
}

void Assignment::dontAdd(int list, int date, int given_assignment) //i think this is a good prarmeter, random types
{
	int count = 0;
	while (list != nullptr)
	{
		if (date <= assigned_date) // dont add if date is less / equal to to assigned date
		{
			//Maybe add list to don't add
		}
		if (date != current_date)
		{
			//add to list to don't add
		}
		for (int i = 0; i != list.end; i++)
		{
			if (given_assignment == list[i])
			{
				//don't add
			}
		}
		
	}
}

int Assignment::count_LA(Item& list, int date) // still unsure about type
{
	
	int countLA = 0;
	while (list != nullptr) 
	{
		if(date >= current_date)
		{
			countLA++;
		}
	}
	return countLA;
}

char Assignment::dont_complete(int listItem, int list1, int list2, int list3) // can add more lists for: late, wip, assigned
{//i am assuming there are already lists made for late, wip and assigned
	while (list1 != nullptr)
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
			if(date >= current_date || date <= current_date || completetion_date != current_date)
			{
				cout << "Don't complete." << endl;
			}
		}
		
	}
}

void Assignment::status(int list, int list1, int list2, int list3)
{
	while(list != nullptr)
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
}