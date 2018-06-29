#ifndef SET_H
#define SET_H

//Set Class declaration
class Set 
{
	private:
		int *setArray;
		int setSize;
	public:
		Set(int inputSize);
		Set(const Set &setObject);
		void RemoveDuplicates();
		void ReadFromFile(char *fileName);
		void ReadSet(char *fileName);
		Set Union(Set setOne, Set setTwo);
		Set Intersection(Set setOne, Set setTwo);
		Set Difference(Set setOne, Set setTwo);
		void PrintSet();
		~Set();
};

#endif
