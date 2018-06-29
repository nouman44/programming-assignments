#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class fraction
{
	private:
		int numerator, denominator;
		static float smallestValue;
		static float largestValue;
		static float averageValue;
		static int num;
		static bool firstInitialize;
		int computeGCD(int a, int b);
		int computeLCM(int a, int b);
		static void IncrementNum();
		void ValueCheck();

	public:
		fraction(int userNum = 0, int userDenom = 1);
		void operator!(void) const; 
		fraction & operator~(void);  
		fraction operator-(void) const;  
		fraction operator*(void) const;  

		fraction & operator+=(const fraction & operand);
		fraction & operator-=(const fraction & operand);
		fraction & operator*=(const fraction & operand);
		fraction & operator/=(const fraction & operand);

											  
		bool operator>(const fraction & operand) const;
		bool operator<(const fraction & operand) const;
		bool operator>=(const fraction & operand) const;
		bool operator<=(const fraction & operand) const;
		bool operator==(const fraction & operand) const;
		bool operator!=(const fraction & operand) const;

		fraction& operator++();
		fraction operator++(int); 
								 
		static float largest();    
		static float smallest();   
		static float average();

		friend ostream & operator<<(ostream &strm, const fraction & f);
		friend istream & operator>>(istream &strm, fraction & f);
};

#endif

