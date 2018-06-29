#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class MyPolynomial
{
	private:
		float *coeffArray;
		float *degreeArray;
		int terms;
		void SortDegreeArray();
		void AddTerm(float degree,float coeff);
		void SimplifyPolynomial();
	public:
		MyPolynomial();
		MyPolynomial(const MyPolynomial &source);
		const MyPolynomial & operator=(const MyPolynomial &source);
		bool operator==(const MyPolynomial &polyObj) const;
		MyPolynomial operator+(const MyPolynomial & operand) const;
		MyPolynomial operator-(const MyPolynomial & operand) const;
		MyPolynomial operator*(const MyPolynomial & operand) const;
		void ReadPolynomial(char *filename);
		void PrintPolynomial();
		~MyPolynomial();
};

#endif
