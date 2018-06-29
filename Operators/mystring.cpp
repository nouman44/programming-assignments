
#include "stdafx.h"
#include <iostream>
#include "mystring.h"
#include <fstream>

using namespace std;

//constructor
MyString::MyString()
{
	strArray = NULL;
	length = 0;
}

//copy constructor
MyString::MyString(const MyString & source)
{
	length = source.length;

	if (length != 0)
	{
		strArray = new char[length];
		strArray[length] = NULL;
	}

	for (int i = 0;i < length;i++)
	{
		strArray[i] = source.strArray[i];
	}
}

//this is operator overload for + operload
//it adds a string to the MyArray object string
MyString MyString::operator+(const char * string) const
{
	MyString strObj;
	int strLength = 0, i, counter = 0;

	for (i = 0;string[i] != NULL;i++)
		strLength++;

	int tempSize = length + strLength;

	char *temp = new char[tempSize];

	for (i = 0;i < length;i++)
	{
		temp[counter] = strArray[i];
		counter++;
	}

	for (i = 0;i < strLength;i++)
	{
		temp[counter] = string[i];
		counter++;
	}

	strObj.length = tempSize;

	strObj.strArray = new char[tempSize + 1];

	for (i = 0;i < tempSize;i++)
	{
		strObj.strArray[i] = temp[i];
	}

	strObj.strArray[tempSize] = NULL;

	delete[] temp;

	return strObj;
}

//this is operator overload for + operload
//it adds the strings of two MyArray objects
MyString MyString::operator+(const MyString & operand) const
{
	MyString strObj;
	int i, counter = 0;

	int tempSize = length + operand.length;

	char *temp = new char[tempSize];

	for (i = 0;i < length;i++)
	{
		temp[counter] = strArray[i];
		counter++;
	}

	for (i = 0;i < operand.length;i++)
	{
		temp[counter] = operand.strArray[i];
		counter++;
	}

	strObj.length = tempSize;

	strObj.strArray = new char[tempSize + 1];

	for (i = 0;i < tempSize;i++)
	{
		strObj.strArray[i] = temp[i];
	}

	strObj.strArray[tempSize] = NULL;

	delete[] temp;

	return strObj;
}

//this is an overload of the = operator
//it assgins the value for R.H.S TO L.H.S
const MyString & MyString::operator=(const MyString & source)
{
	if (this != &source)
	{
		length = source.length;

		if (strArray != NULL)
			delete[] strArray;

		if (source.length != 0)
		{
			strArray = new char[length+1];

			for (int i = 0;i < length;i++)
			{
				strArray[i] = source.strArray[i];
			}

			strArray[length] = NULL;
		}
		else
			strArray = NULL;
	}
	
	return *this;
}

//this is an overload of the == operator
//it checks whether strings of two MyArray objects are equal
bool MyString::operator==(const MyString & operand) const
{
	bool isEqual = true;

	if (length != operand.length)
		isEqual = false;

	for (int i = 0;i < length && isEqual;i++)
	{
		if (strArray[i] != operand.strArray[i])
			isEqual = false;
	}

	return isEqual;
}

//this is an overload of the [] operator
//it is an accessor function
const char & MyString::operator[](int index) const
{
	char *charToReturn = &strArray[0];

	if (index >= 0 && index < length)
		charToReturn = &strArray[index];
	else if (index >= length)
		charToReturn = &strArray[length - 1];

	return *charToReturn;
}

//this is an overload of the [] operator
//it is a mutator function
char & MyString::operator[](int index)
{
	char *charReturn = &(strArray[0]);

	if (index >= 0 && index < length)
		charReturn = &(strArray[index]);
	else if (index >= length)
		charReturn = &(strArray[length - 1]);

	return *charReturn;
}

//this is an overload of the < operator
//it checks if the string of an object is lesser than of other object
bool MyString::operator<(const MyString & operand) const
{
	bool isLess = true, isSame = true;

	int i, counter;

	if (length < operand.length)
		counter = length;
	else
		counter = operand.length;

	for (i = 0;i < counter && isSame;i++)
	{
		if (strArray[i] > operand.strArray[i])
			isLess = false;

		if (strArray[i] != operand.strArray[i])
			isSame = false;
	}

	if (isSame)
	{
		if (length == operand.length)
			isLess = false;
		else if (length > operand.length)
			isLess = false;
	}

	return isLess;
}

//this is an overload of the > operator
//it checks if the string of an object is greater than of other object
bool MyString::operator>(const MyString & operand) const
{
	bool isGreater = true, isSame = true;

	int i, counter;

	if (length < operand.length)
		counter = length;
	else
		counter = operand.length;

	for (i = 0;i < counter && isSame;i++)
	{
		if (strArray[i] < operand.strArray[i])
			isGreater = false;

		if (strArray[i] != operand.strArray[i])
			isSame = false;
	}

	if (isSame)
	{
		if (length == operand.length)
			isGreater = false;
		else if (length < operand.length)
			isGreater = false;
	}

	return isGreater;
}


//overload for stream insertion operator <<
ostream & operator<<(ostream &strm, const MyString &string)
{
	strm << string.strArray << endl;

	return strm;
}

//overload for stream extraction operator >>
istream & operator>>(istream &strm, MyString &string)
{
	char *temp = new char[250];
	int i, size = 0;

	strm.getline(temp,100);

	for (i = 0;temp[i] != NULL;i++)
		size++;

	if (string.strArray != NULL)
		delete[] string.strArray;

	string.length = size;

	string.strArray = new char[size + 1];

	for (i = 0;i < size;i++)
		string.strArray[i] = temp[i];

	string.strArray[size] = NULL;
	
	delete[] temp;

	return strm;
}

//function to read string from file
void MyString::ReadFromFile(char * filename)
{
	ifstream inputStrm(filename);

	if (inputStrm.is_open())
		inputStrm >> *this;

	inputStrm.close();
}

//function to write string to file
void MyString::WriteToFile(char * filename)
{
	ofstream outputStrm(filename);

	if(outputStrm.is_open())
		outputStrm << *this;

	outputStrm.close();
}


MyString::~MyString()
{

}

