
#include "stdafx.h"
#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
	fraction fracA, fracB;
	int choice = 1, index;
	bool check;

	cout << "Welcome to the Fraction program!" << endl;
	cout << "Please enter the choice to do the required step: " << endl;
	cout << "0: Exit" << endl;
	cout << "1: Input fraction A" << endl;
	cout << "2: Input fraction B" << endl;
	cout << "3: Print fraction A" << endl;
	cout << "4: Print fraction B" << endl;
	cout << "5: Reduce fraction A" << endl;
	cout << "6: Reduce fraction B" << endl;
	cout << "7: Print negative of fraction A" << endl;
	cout << "8: Print negative of fraction B" << endl;
	cout << "9: Print reciprocal of fraction A" << endl;
	cout << "10: Print reciprocal of fraction B" << endl;
	cout << "11: Add fraction B to fraction A" << endl;
	cout << "12: Subtract fraction B from fraction A" << endl;
	cout << "13: Multiply fraction A by fraction B" << endl;
	cout << "14: Divide fraction A by fraction B" << endl;
	cout << "15: Check if fraction A is greater than fraction B" << endl;
	cout << "16: Check if fraction A is less than fraction B" << endl;
	cout << "17: Check if fraction A is greater and equal to fraction B" << endl;
	cout << "18: Check if fraction A is less and equal to fraction B" << endl;
	cout << "19: Check if fraction A is equal to fraction B" << endl;
	cout << "20: Check if fraction A is not equal to fraction B" << endl;
	cout << "21: Ouput largest fraction" << endl;
	cout << "22: Ouput smallest fraction" << endl;
	cout << "23: Output average value" << endl;
	cout << "24: Use the prefix operator on fracA" << endl;
	cout << "24: Use the postfix operator on fracB" << endl;

	while (choice != 0)
	{
		cout << endl << "Please enter a choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 0:
			break;
		case 1:
			cin >> fracA;
			break;
		case 2:
			cin >> fracB;
			break;
		case 3:
			!fracA;
			break;
		case 4:
			!fracB;
			break;
		case 5:
			fracA = ~fracA;
			break;
		case 6:
			fracB = ~fracB;
			break;
		case 7:
			cout << -fracA;
			break;
		case 8:
			cout << -fracB;			
			break;
		case 9:
			cout << *fracA;
			break;
		case 10:
			cout << *fracB;
			break;
		case 11:
			fracA += fracB;
			cout << "Operation successful!" << endl;
			break;
		case 12:
			fracA -= fracB;
			cout << "Operation successful!" << endl;
			break;
		case 13:
			fracA *= fracB;
			cout << "Operation successful!" << endl;
			break;
		case 14:
			fracA /= fracB;
			cout << "Operation successful!" << endl;
			break;
		case 15:
			check = (fracA > fracB);
			if (check)
				cout << "Fraction A is greater than B" << endl;
			else
				cout << "Fraction A is NOT greater than B" << endl;
			break;
		case 16:
			check = (fracA < fracB);
			if (check)
				cout << "Fraction A is lesser than B" << endl;
			else
				cout << "Fraction A is NOT lesser than B" << endl;
			break;
			break;
		case 17:
			check = (fracA >= fracB);
			if (check)
				cout << "Fraction A is greater and equal to B" << endl;
			else
				cout << "Fraction A is NOT greater and equal B" << endl;
			break;
			break;
		case 18:
			check = (fracA <= fracB);
			if (check)
				cout << "Fraction A is less and equal to B" << endl;
			else
				cout << "Fraction A is NOT less and equal to B" << endl;
			break;
		case 19:
			check = (fracA == fracB);
			if (check)
				cout << "Fraction A is euqal to B" << endl;
			else
				cout << "Fraction A is NOT equal to B" << endl;
			break;
		case 20:
			check = (fracA != fracB);
			if (check)
				cout << "Fraction A is not equal to B" << endl;
			else
				cout << "Fraction A IS equal to B" << endl;
			break;
		case 21:
			cout << "The largest fraction is: " << fraction::largest() << endl;
			break;
		case 22:
			cout << "The smallest fraction is: " << fraction::smallest() << endl;
			break;
		case 23:
			cout << "The average value is: " << fraction::average() << endl;
			break;
		case 24:
			cout << ++fracA;
			break;
		case 25:
			cout << fracB++;
			break;
		default:
			cout << "Please input a valid choice" << endl;
			break;
		}
	}

	return 0;
}

