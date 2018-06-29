
#include <iostream>
#include "set.h"

using namespace std;

int main()
{
	//variable declarations
	int choice = 1, printChoice;
	Set setOne(0);
	Set setTwo(0);
	Set result(0);
	
	//file name declarations
	char *fileName = "sampleSet.txt";
	char *fileName2 = "sampleSet2.txt";

	//default choices in menu
	cout << "You can perform the following action related to sets: " << endl;
	cout << "ENTER: " << endl;
	cout << "1 for reading Set 1 from file" << endl;
	cout << "2 for reading Set 2 from file" << endl;
	cout << "3 for Printing a specific set" << endl;
	cout << "4 to find Union of the two sets" << endl;
	cout << "5 to find Intersection of the two sets" << endl;
	cout << "6 to find the Difference of the two sets" << endl << endl;
	cout << "OR enter 0 to end program!" << endl;

	//loop to take continuous input of choice
	while (choice != 0)
	{
		cin >> choice;

		if (choice != 0)
		{
			//switch to perform action according to choice
			switch (choice)
			{
			case 1:
				setOne.ReadSet(fileName);
				cout << "Set 1 has been read from file!" << endl;
				break;
			case 2:
				setTwo.ReadSet(fileName2);
				cout << "Set 2 has been read from file!" << endl;
				break;
			case 3:
				cout << "ENTER: " << endl;
				cout << "1 for printing Set 1" << endl;
				cout << "2 for prtinting Set 2" << endl;
				cout << "3 for printing Result Set" << endl;
				cin >> printChoice;
				if (printChoice == 1)
				{
					cout << "Set 1 = ";
					setOne.PrintSet();
				}
				else if (printChoice == 2)
				{
					cout << "Set 2 = ";
					setTwo.PrintSet();
				}
				else if (printChoice == 3)
				{
					cout << "Result = ";
					result.PrintSet();
				}
				else
					cout << "Please enter valid print choice!" << endl;
				break;
			case 4:
				result = result.Union(setOne, setTwo);
				cout << "Union has been stored in result set!" << endl;
				break;
			case 5:
				result = result.Intersection(setOne, setTwo);
				cout << "Intersection has been stored in result set!" << endl;
				break;
			case 6:
				result = result.Difference(setOne, setTwo);
				cout << "Difference has been stored in result set!" << endl;
				break;
			default:
				cout << "Please enter a valid choice: " << endl;
				break;
			}
		}

		cout << endl << "Enter next choice: " << endl;
	}

    return 0;
}

