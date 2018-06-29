
#include "stdafx.h"
#include <iostream>
#include "mystring.h"

using namespace std;

int main()
{
	MyString strA, strB, strC;
	char *filename = new char[50];
	char *filename2 = new char[50];
	char temp[250];
	int choice = 1, index;
	bool strCheck;
	char c;

	cout << "Welcome to the String program!" << endl;
	cout << "Please enter the choice to do the required step: " << endl;
	cout << "0: Exit" << endl;
	cout << "1: Input string A from file" << endl;
	cout << "2: Input string B from file" << endl;
	cout << "3: Input string A manually (by typing)" << endl;
	cout << "4: Input string B manually (by typing)" << endl;
	cout << "5: Add something to string A" << endl;
	cout << "6: Add something to string B" << endl;
	cout << "7: Add string A and B to get string C" << endl;
	cout << "8: Output string A to file" << endl;
	cout << "9: Output string B to file" << endl;
	cout << "10: Output string C to file" << endl;
	cout << "11: Output string A on screen" << endl;
	cout << "12: Output string B on screen" << endl;
	cout << "13: Output string C on screen" << endl;
	cout << "14: Change a character in string A"<< endl;
	cout << "15: Change a character in string B" << endl;
	cout << "16: Store and output a character from string A" << endl;
	cout << "17: Store and output a character from string B" << endl;
	cout << "18: Check if string A is lesser than string B" << endl;
	cout << "19: Check if string A is greater than string B" << endl;
	cout << "20: Check if string A is equal to string B" << endl;

	while (choice != 0)
	{
		cout << endl << "Please enter a choice: ";
		cin >> choice;
		cin.ignore(cin.rdbuf()->in_avail(), '\n'); //to make cin.getline work in while loop
		cout << endl;

		switch (choice)
		{
			case 0:
				break;
			case 1:
				cout << "Input file name to read A from (i.e. 'sample1.txt'): ";
				cin >> filename;
				strA.ReadFromFile(filename);
				break;
			case 2:
				cout << "Input file name to read B from (i.e. 'sample2.txt'): ";
				cin >> filename2;
				strB.ReadFromFile(filename2);
				break;
			case 3:
				cout << "Enter string A: ";
				cin >> strA;
				break;
			case 4:
				cout << "Enter string B: ";
				cin >> strB;
				break;
			case 5:
				cout << "Enter what you want to add to string A: ";
				cin.getline(temp, 100);
				strA = strA + temp;
				break;
			case 6:
				cout << "Enter what you want to add to string B: ";
				cin.getline(temp, 100);
				strB = strB + temp;
				break;
			case 7:
				strC = strA + strB;
				cout << "Strings added successfully!" << endl;
				break;
			case 8:
				cout << "Input file name to write A to:";
				cin >> filename;
				strA.WriteToFile(filename);
				break;
			case 9:
				cout << "Input file name to write B to:";
				cin >> filename2;
				strB.WriteToFile(filename2);
				break;
			case 10:
				cout << "Input file name to write C to:";
				cin >> filename;
				strC.WriteToFile(filename);
				break;
			case 11:
				cout << strA;
				break;
			case 12:
				cout << strB;
				break;
			case 13:
				cout << strC;
				break;
			case 14:
				cout << "Enter index of char you want to change in string A: ";
				cin >> index;
				cout << "Input the char you want to replace it with: ";
				cin >> c;
				strA[index] = c;
				break;
			case 15:
				cout << "Enter index of char you want to change in string B: ";
				cin >> index;
				cout << "Input the char you want to replace it with: ";
				cin >> c;
				strB[index] = c;
				break;
			case 16:
				cout << "Enter index of char you want to store from string A: ";
				cin >> index;
				c = strA[index];
				cout << c << endl;
				break;
			case 17:
				cout << "Enter index of char you want to store from string B: ";
				cin >> index;
				c = strB[index];
				cout << c << endl;
				break;
			case 18:
				strCheck = (strA < strB);
				if (strCheck)
					cout << "string A is lesser than string B" << endl;
				else
					cout << "string A is NOT less than string B" << endl;
				break;
			case 19:
				strCheck = (strA > strB);
				if (strCheck)
					cout << "string A is greater than string B" << endl;
				else
					cout << "string A is NOT greater than string B" << endl;
				break;
			case 20:
				strCheck = (strA == strB);
				if (strCheck)
					cout << "string A is equal to string B" << endl;
				else
					cout << "string A is NOT equal to string B" << endl;
				break;
			default:
				cout << "Please input a valid choice" << endl;
				break;
		}
	}

	return 0;
}

