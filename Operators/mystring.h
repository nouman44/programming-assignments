#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using namespace std;

class MyString
{
	private:
		char *strArray;
		int length;
	public:
		MyString(); //constructor
		MyString(const MyString & source); //copy constructor
		MyString operator+(const char *string) const; //overload for + operator for char* type
		MyString operator+(const MyString & operand) const; //overload for + operator for Mystring type
		const MyString & operator=(const MyString & source); //overload for = operator
		bool operator==(const MyString & operand) const; //overload for == operator
		const char & operator[](int index) const; //overload for [] operator (accessor)
		char & operator[](int index); //overload for [] operator (mutator)
		bool operator<(const MyString & operand) const; //overload for < operator
		bool operator>(const MyString & operand) const; //overload for > operator
		friend ostream & operator<<(ostream &strm, const MyString &string); //overload for stream insertion operator <<
		friend istream & operator>>(istream &strm, MyString &string); //overload for stream extraction operator >>
		void ReadFromFile(char *filename); //function to read string from file
		void WriteToFile(char *filename); //function to write string to file
		~MyString(); //destructor
};

#endif
