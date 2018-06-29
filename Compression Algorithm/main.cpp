#include <iostream>
#include <fstream>

using namespace std;

//function to convert the char into hex code
unsigned char convertLetterToCode(char letter)
{
	unsigned char num;

	//switch to match right case
	switch(letter)
	{
		case '0':
			num = 0;
			break;
		case '1':
			num = 1;
			break;
		case '2':
			num = 2;
			break;
		case '3':
			num = 3;
			break;
		case '4':
			num = 4;
			break;
		case '5':
			num = 5;
			break;
		case '6':
			num = 6;
			break;
		case '7':
			num = 7;
			break;
		case '8':
			num = 8;
			break;
		case '9':
			num = 9;
			break;
		case ' ':
			num = 10;
			break;
		case '.':
			num = 11;
			break;
		case '+':
			num = 12;
			break;
		case '-':
			num = 13;
			break;
		case '=':
			num = 14;
			break;
		default:
			num = 15;
			break;
	}

	return num;
}

//function to convert the number value to required character
char convertToLetter(unsigned char num)
{
	char letter;

	//switch to match right case
	switch(num)
	{
		case 0:
			letter = '0';
			break;
		case 1:
			letter = '1';
			break;
		case 2:
			letter = '2';
			break;
		case 3:
			letter = '3';
			break;
		case 4:
			letter = '4';
			break;
		case 5:
			letter = '5';
			break;
		case 6:
			letter = '6';
			break;
		case 7:
			letter = '7';
			break;
		case 8:
			letter = '8';
			break;
		case 9:
			letter = '9';
			break;
		case 10:
			letter = ' ';
			break;
		case 11:
			letter = '.';
			break;
		case 12:
			letter = '+';
			break;
		case 13:
			letter = '-';
			break;
		case 14:
			letter = '=';
			break;
		default:
			letter = '#';
			break;
	}

	return letter;
}

//function to take a code and convert it into two required characters
void convertCodeToCharacters(unsigned char code, unsigned char &first, unsigned char &second)
{
	unsigned char x = 15;
	
	first = code >> 4;
	second = code & x;
	
	first = convertToLetter(first);
	second = convertToLetter(second);
}

//main driver function that compresses the text file into binary file
void Compress(char *inputTextFileName, char *outputBinaryFileName)
{
	//declaring the file streams
	ifstream inputStream(inputTextFileName);
	ofstream outputStream(outputBinaryFileName);

	char letter;
	unsigned char num;
	unsigned char first,second;
	bool carryOn = true;

	while(!inputStream.eof())
	{
		inputStream.get(letter);
		num = convertLetterToCode(letter);		
		
		if(!inputStream.eof())
		{
			first = num << 4;
			inputStream.get(letter);
			num = convertLetterToCode(letter);
			second = num;
			num = first | second;
		}
		
		outputStream << num;
	}
	
	//closing both file streams
	inputStream.close();
	outputStream.close();
}

//main driver function that decompresses the binary file into text file
void Decompress(char *inputBinaryFileName, char *outputTextFileName)
{
	//declaring the file streams
	ifstream inputStream(inputBinaryFileName,ios::binary|ios::out) ;
	ofstream outputStream(outputTextFileName);
	
	unsigned char c,first,second;
	
	while(!inputStream.eof())
	{
		inputStream.read((char *) &c,1);  
		convertCodeToCharacters(c,first,second);
		
		outputStream << first << second;
	}
	
	//closing both file streams
	inputStream.close();
	outputStream.close();
}

int main()
{
	int size = 100;
	
	//declaration of all required pointer variables and dynamic memory allocated alongside
	char *inputTextFileName = new char[size];
	char *outputBinaryFileName = new char[size];
	char *inputBinaryFileName = new char[size];
	char *outputTextFileName = new char[size];
	
	//taking inputs for compression
	cout << "Enter the name of the text file to compress (write .txt also): ";
	cin.getline(inputTextFileName,size);
	cout << "Enter the name of the binary file to create after compresssion (write .bin also): ";
	cin.getline(outputBinaryFileName,size);
	
	//taking inputs for decompression
	cout << "Enter the name of the binary file to decompress (write .bin also): ";
	cin.getline(inputBinaryFileName,size);
	cout << "Enter the name of the text file to create after decompression (write .txt also): ";
	cin.getline(outputTextFileName,size);
	
	//function call for compression
	Compress(inputTextFileName, outputBinaryFileName);
	
	//function call for decompression
	Decompress(inputBinaryFileName,outputTextFileName);
	
	//deleteing the dynamic allocated memory
	delete[] inputTextFileName;
	delete[] outputBinaryFileName;
	delete[] inputBinaryFileName;
	delete[] outputTextFileName;
	
	//assigning all the pointers NULL value
	inputTextFileName = NULL;
	outputBinaryFileName = NULL;
	inputBinaryFileName = NULL;
	outputTextFileName = NULL;
	
    return 0;	
}

