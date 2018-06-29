
#include <iostream>
#include "polynomial.h"

using namespace std;


int main()
{
	MyPolynomial a, b, c;
	char *filename = new char[50];
	char *filename2 = new char[50];
	int choice = 1;
	bool isEqual;

	cout << "Welcome to the Polynomial program!" << endl;
	cout << "Please enter the choice to do the required step: " << endl;
	cout << "0: Exit" << endl;
	cout << "1: Input polynomial a from file" << endl;
	cout << "2: Input polynomial b from file" << endl;
	cout << "3: Add a and b to give c" << endl;
	cout << "4: Multiply a and b to give c" << endl;
	cout << "5: Subtract a from b to give c" << endl;
	cout << "6: Print polynomial a" << endl;
	cout << "7: Print polynomial b" << endl;
	cout << "8: Print polynomial c" << endl;
	cout << "9: Check a==b" << endl;

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
				cout << "Input file name to read a from (i.e. 'poly1.txt'): ";
				cin >> filename;
				a.ReadPolynomial(filename);
				break;
			case 2:
				cout << "Input file name to read b from (i.e. 'poly2.txt'): ";
				cin >> filename2;
				b.ReadPolynomial(filename2);
				break;
			case 3:
				c = a + b;
				cout << "Addition successful" << endl;
				break;
			case 4:
				c = a * b;
				cout << "Multiplication successful" << endl;
				break;
			case 5:
				c = b - a;
				cout << "Subtraction successful" << endl;
				break;
			case 6:
				cout << "a = ";
				a.PrintPolynomial();
				break;
			case 7:
				cout << "b = ";
				b.PrintPolynomial();
				break;
			case 8:
				cout << "c = ";
				c.PrintPolynomial();
				break;
			case 9:
				isEqual = (a == b);
				if (isEqual)
					cout << "a and b are equal!" << endl;
				else
					cout << "a and b are not equal!" << endl;
				break;
			default:
				cout << "Please input a valid choice" << endl;
				break;
		}
	}

	return 0;
}

