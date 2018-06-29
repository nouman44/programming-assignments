
#include <iostream>
#include <fstream>
#include "set.h"

using namespace std;

//default constructor with size as parameter
Set::Set(int inputSize)
{
	setSize = inputSize;
	setArray = new int[setSize];
}

//Copy Constructor
Set::Set(const Set &setObject)
{
	setSize = setObject.setSize;
	setArray = new int[setSize];

	for (int i = 0;i < setSize;i++)
	{
		setArray[i] = setObject.setArray[i];
	}
}

//function to remove duplicate items from set
void Set::RemoveDuplicates()
{
	int i, j;
	int newSize = 0;
	bool matchFound;
	int *TempArr = new int[setSize];

	for (i = 0;i < setSize;i++)
	{
		matchFound = false;

		for (j = 0;j < newSize && !matchFound;j++)
		{
			if (setArray[i] == TempArr[j])
				matchFound = true;
		}
		if (!matchFound)
		{
			TempArr[newSize] = setArray[i];
			newSize++;
		}
	}

	setSize = newSize;
	delete[] setArray;
	setArray = new int[setSize];

	for (i = 0;i < setSize;i++)
	{
		setArray[i] = TempArr[i];
	}

	delete[] TempArr;
}

//function to read set size and elements from a file
void Set::ReadFromFile(char *fileName)
{
	ifstream inputStream(fileName);
	int input;

	inputStream >> input;
	setSize = input;

	delete[] setArray;
	setArray = new int[setSize];

	for (int i = 0;i < setSize;i++)
	{
		inputStream >> input;
		setArray[i] = input;
	}
}

//function to call ReadFromFile function and RemoveDuplicates also
void Set::ReadSet(char *fileName)
{
	ReadFromFile(fileName);
	RemoveDuplicates();
}

//function to find the union of two input sets
//it then returns the resulting set as a Set Class object
Set Set::Union(Set setOne, Set setTwo)
{
	Set result(setOne);
	int i, j;
	bool matchFound = false;

	for (i = 0;i < setTwo.setSize;i++)
	{
		matchFound = false;

		for (j = 0;j < result.setSize && !matchFound;j++)
		{
			if (setTwo.setArray[i] == result.setArray[j])
				matchFound = true;
		}
		if (!matchFound)
		{
			result.setArray[result.setSize] = setTwo.setArray[i];
			result.setSize++;
		}
	}

	return result;
}

//function to find the intersection of two input sets
//it then returns the resulting set as a Set Class object
Set Set::Intersection(Set setOne, Set setTwo)
{
	Set result(0);
	int i, j;
	bool matchFound = false;

	for (i = 0;i < setOne.setSize;i++)
	{
		matchFound = false;

		for (j = 0;j < setTwo.setSize && !matchFound;j++)
		{
			if (setOne.setArray[i] == setTwo.setArray[j])
				matchFound = true;
		}
		if (matchFound)
		{
			result.setArray[result.setSize] = setOne.setArray[i];
			result.setSize++;
		}
	}

	return result;
}

//function to find the difference of two input sets
//it then returns the resulting set as a Set Class object
Set Set::Difference(Set setOne, Set setTwo)
{
	Set result(0);
	int i, j;
	bool matchFound = false;

	for (i = 0;i < setOne.setSize;i++)
	{
		matchFound = false;

		for (j = 0;j < setTwo.setSize && !matchFound;j++)
		{
			if (setOne.setArray[i] == setTwo.setArray[j])
				matchFound = true;
		}
		if (!matchFound)
		{
			result.setArray[result.setSize] = setOne.setArray[i];
			result.setSize++;
		}
	}

	return result;
}

//function to print the set in the right format
void Set::PrintSet()
{
	cout << "{";
	for (int i = 0;i < setSize;i++)
	{
		cout << setArray[i] << ",";
	}
	cout << "}";

	cout << endl;
}


Set::~Set()
{
}
