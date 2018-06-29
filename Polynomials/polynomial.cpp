
#include <iostream>
#include <fstream>
#include "polynomial.h"

using namespace std;

void MyPolynomial::SortDegreeArray()
{
	int i, j, max;
	float temp1, temp2;

	for (i = 0;i < terms - 1;i++)
	{
		max = i;

		for (j = i + 1;j < terms;j++)
		{
			if (degreeArray[j] > degreeArray[max])
				max = j;
		}

		if (max != i)
		{
			temp1 = degreeArray[i];
			temp2 = coeffArray[i];
			degreeArray[i] = degreeArray[max];
			coeffArray[i] = coeffArray[max];
			degreeArray[max] = temp1;
			coeffArray[max] = temp2;
		}
	}
}

void MyPolynomial::AddTerm(float degree, float coeff)
{
	int i;
	float *tempDegree = new float[terms];
	float *tempCoeff = new float[terms];

	for (i = 0;i < terms;i++)
	{
		tempDegree[i] = degreeArray[i];
		tempCoeff[i] = coeffArray[i];
	}

	delete[] degreeArray;
	delete[] coeffArray;

	degreeArray = new float[terms + 1];
	coeffArray = new float[terms + 1];

	for (i = 0;i < terms;i++)
	{
		degreeArray[i] = tempDegree[i];
		coeffArray[i] = tempCoeff[i];
	}

	degreeArray[terms] = degree;
	coeffArray[terms] = coeff;

	terms++;

	delete[] tempDegree;
	delete[] tempCoeff;
}

void MyPolynomial::SimplifyPolynomial()
{
	int i, j, k, size = 0;
	bool doesExist = false;
	float *tempDegree = new float[terms];
	float *tempCoeff = new float[terms];

	for (i = 0;i < terms;i++)
	{
		doesExist = false;

		for (j = 0;j < size && !doesExist;j++)
		{
			if (tempDegree[j] == degreeArray[i])
				doesExist = true;
		}

		if (!doesExist)
		{
			tempDegree[size] = degreeArray[i];
			tempCoeff[size] = coeffArray[i];

			for (k = i + 1;k < terms;k++)
			{
				if (degreeArray[i] == degreeArray[k])
					tempCoeff[size] = tempCoeff[size] + coeffArray[k];
			}

			size++;
		}
	}

	delete[] degreeArray;
	delete[] coeffArray;

	terms = size;

	degreeArray = new float[terms];
	coeffArray = new float[terms];

	for (i = 0;i < terms;i++)
	{
		degreeArray[i] = tempDegree[i];
		coeffArray[i] = tempCoeff[i];
	}

	delete[] tempDegree;
	delete[] tempCoeff;
}

MyPolynomial::MyPolynomial()
{
	terms = 0;
	degreeArray = NULL;
	coeffArray = NULL;
}

MyPolynomial::MyPolynomial(const MyPolynomial & source)
{
	terms = source.terms;

	if (terms != 0)
	{
		degreeArray = new float[terms];
		coeffArray = new float[terms];
	}

	for (int i = 0;i < terms;i++)
	{
		degreeArray[i] = source.degreeArray[i];
		coeffArray[i] = source.coeffArray[i];
	}
}

const MyPolynomial & MyPolynomial::operator=(const MyPolynomial & source)
{
	if (this != &source)
	{
		if (terms != 0)
		{
			delete[] degreeArray;
			delete[] coeffArray;
		}

		terms = source.terms;

		if (terms != 0)
		{
			degreeArray = new float[terms];
			coeffArray = new float[terms];

			for (int i = 0;i < terms;i++)
			{
				degreeArray[i] = source.degreeArray[i];
				coeffArray[i] = source.coeffArray[i];
			}
		}
		else
		{
			degreeArray = NULL;
			coeffArray = NULL;
		}
	}

	return *this;
}

bool MyPolynomial::operator==(const MyPolynomial & polyObj) const
{
	int i;
	bool isEqual = true;

	if (terms != polyObj.terms)
		isEqual = false;

	for (i = 0;i < terms && isEqual;i++);
	{
		if (degreeArray[i] != polyObj.degreeArray[i] || coeffArray[i] != polyObj.coeffArray[i])
			isEqual = false;
	}

	return isEqual;
}

MyPolynomial MyPolynomial::operator+(const MyPolynomial & operand) const
{
	MyPolynomial polyObj(*this);
	int i, j, index;
	bool doesExist = false;
	
	for (i = 0;i < operand.terms;i++)
	{
		index = 0;
		doesExist = false;

		for (j = 0;j < polyObj.terms && !doesExist;j++)
		{
			if (operand.degreeArray[i] == polyObj.degreeArray[j])
			{
				doesExist = true;
				index = j;
			}
		}

		if (!doesExist)
		{
			polyObj.AddTerm(operand.degreeArray[i], operand.coeffArray[i]);
		}
		else 
		{
			polyObj.coeffArray[index] = polyObj.coeffArray[index] + operand.coeffArray[i];
		}
	}

	polyObj.SortDegreeArray();

	return polyObj;
}

MyPolynomial MyPolynomial::operator-(const MyPolynomial & operand) const
{
	MyPolynomial polyObj(*this);
	int i, j, index;
	bool doesExist = false;

	for (i = 0;i < operand.terms;i++)
	{
		index = 0;
		doesExist = false;

		for (j = 0;j < polyObj.terms && !doesExist;j++)
		{
			if (operand.degreeArray[i] == polyObj.degreeArray[j])
			{
				doesExist = true;
				index = j;
			}
		}

		if (!doesExist)
		{
			polyObj.AddTerm(operand.degreeArray[i], -operand.coeffArray[i]);
		}
		else
		{
			polyObj.coeffArray[index] = polyObj.coeffArray[index] - operand.coeffArray[i];
		}
	}

	polyObj.SortDegreeArray();

	return polyObj;
}

MyPolynomial MyPolynomial::operator*(const MyPolynomial & operand) const
{
	MyPolynomial polyObj;
	int i, j;
	float degree, coeff;

	for (i = 0;i < terms;i++)
	{
		for (j = 0;j < operand.terms;j++)
		{
			degree = degreeArray[i] + operand.degreeArray[j];
			coeff = coeffArray[i] * operand.coeffArray[j];
			polyObj.AddTerm(degree, coeff);
		}
	}

	polyObj.SimplifyPolynomial();

	polyObj.SortDegreeArray();

	return polyObj;
}

void MyPolynomial::ReadPolynomial(char * filename)
{
	ifstream inputStream(filename);
	int i, x;
	float reader;

	inputStream >> x;
	terms = x;

	degreeArray = new float[terms];
	coeffArray = new float[terms];

	for (i = 0;i < terms;i++)
	{
		inputStream >> reader;
		degreeArray[i] = reader;
	}

	for (i = 0;i < terms;i++)
	{
		inputStream >> reader;
		coeffArray[i] = reader;
	}
}

void MyPolynomial::PrintPolynomial()
{
	for (int i = 0;i < terms;i++)
	{
		if (coeffArray[i] < 0)
			cout << coeffArray[i] << "x" << "^" << degreeArray[i];
		else
			cout << "+" << coeffArray[i] << "x" << "^" << degreeArray[i];
	}

	cout << endl;
}

MyPolynomial::~MyPolynomial()
{
	delete[] coeffArray;
	delete[] degreeArray;
}
