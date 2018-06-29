#include <iostream>
#include <math.h>
#include <windows.h>
#include "mygraphics.h"

using namespace std;

//this funnction checks whether a number is prime or not
bool IsPrime(int x)
{
	bool checkPrime = true;
	int max = floor(sqrt(x));
	
	for(int i=2;i<=max && checkPrime;i++)
	{
		if(x%i == 0)
			checkPrime = false;
	}
	
	return checkPrime;
}

//this function stores an intger into a character array
void convertToStr(int n,char str[])
{
	int size = 0;
	int x = n;
	int i,divider,remainder;
	
	while(x!=0)
	{
		x/=10;
		size++;
	}
	
	remainder = pow(10,size);
	divider = pow(10,size-1);
	
	for(i=0;i<size;i++)
	{
		x = n;
		x = x % remainder;
		x = x / divider;
		
		str[i] = x + 48;
		
		remainder/=10;
		divider/=10;
	}
}

//this functions draws the required spiral and the required statistics
void drawSpiral(int n)
{
	//declaration of all required colors
	COLORREF redColor = RGB(255,0,0);
	COLORREF blueColor = RGB(0,0,255);
	COLORREF backGround = RGB(0,0,0);
	COLORREF whiteColor = RGB(255,255,255);
	
	char str[10] = "1";
	
	int number = 1;
	int i;
	int x = 300;
	int y = 300;
	int size = 10;
	int step = 30;
	int times = 1;
	int diff1=5,diff2=8,diff3=10,diff4=15;
	int cornerCounter=0,primeCounter=0,cornerprimeCounter=0;
	
	bool spiralComplete = false;
	bool primeCheck = false;
	
	myDrawText(x,y,size,str,whiteColor,backGround);
	
	//loop executes until spiral is drawn
	while(!spiralComplete)
	{
		//loop for drawing spiral to the RIGHT
		for(i=0;i<times && !spiralComplete;i++)
		{
			if(number<10)
				myLine(x+diff3,y+diff2,x+step,y+diff2,redColor);
			else
				myLine(x+diff4,y+diff2,x+step,y+diff2,redColor);
			
			x+=step;
			number++;
			convertToStr(number,str);
			
			//condition to check for corner
			if(i!=times-1)
			{
				if(IsPrime(number))
				{
					myDrawText(x,y,size,str,redColor,backGround);
					primeCounter++;
				}
				else
					myDrawText(x,y,size,str,whiteColor,backGround);
			}
			else
			{
				if(IsPrime(number))
				{
					myDrawText(x,y,size,str,blueColor,backGround);
					cornerCounter++;
					primeCounter++;
					cornerprimeCounter++;
				}
				else
				{
					myDrawText(x,y,size,str,whiteColor,backGround);
					cornerCounter++;
				}
			}
			
			if(number==n)
				spiralComplete = true;
		}
		
		//loop for drawing spiral to the TOP
		for(i=0;i<times && !spiralComplete;i++)
		{
			if(number<10)
				myLine(x+diff1,y,x+diff1,y-step,redColor);
			else
				myLine(x+diff1,y,x+diff1,y-step,redColor);
			
			y-=step;
			number++;
			convertToStr(number,str);
			
			//condition to check for corner
			if(i!=times-1)
			{
				if(IsPrime(number))
				{
					myDrawText(x,y,size,str,redColor,backGround);
					primeCounter++;
				}
				else
					myDrawText(x,y,size,str,whiteColor,backGround);
			}
			else
			{
				if(IsPrime(number))
				{
					myDrawText(x,y,size,str,blueColor,backGround);
					cornerCounter++;
					primeCounter++;
					cornerprimeCounter++;
				}
				else
				{
					myDrawText(x,y,size,str,whiteColor,backGround);
					cornerCounter++;
				}
			}
			
			if(number==n)
				spiralComplete = true;
		}
		
		times++;
		
		//loop for drawing spiral to the LEFT
		for(i=0;i<times && !spiralComplete;i++)
		{
			if(number<10)
				myLine(x-diff1,y+diff2,x-step,y+diff2,redColor);
			else
				myLine(x,y+diff2,x-step,y+diff2,redColor);
			
			x-=step;
			number++;
			convertToStr(number,str);
			
			//condition to check for corner
			if(i!=times-1)
			{
				if(IsPrime(number))
				{
					myDrawText(x,y,size,str,redColor,backGround);
					primeCounter++;
				}
				else
					myDrawText(x,y,size,str,whiteColor,backGround);
			}
			else
			{
				if(IsPrime(number))
				{
					myDrawText(x,y,size,str,blueColor,backGround);
					cornerCounter++;
					primeCounter++;
					cornerprimeCounter++;
				}
				else
				{
					myDrawText(x,y,size,str,whiteColor,backGround);
					cornerCounter++;
				}
			}
			
			if(number==n)
				spiralComplete = true;
		}
		
		//loop for drawing spiral to the BOTTOM
		for(i=0;i<times && !spiralComplete;i++)
		{
			if(number<10)
				myLine(x+diff1,y+diff4,x+diff1,y+step,redColor);
			else
				myLine(x+diff1,y+diff4,x+diff1,y+step,redColor);
			
			y+=step;
			number++;
			convertToStr(number,str);

			//condition to check for corner
			if(i!=times-1)
			{
				if(IsPrime(number))
				{
					myDrawText(x,y,size,str,redColor,backGround);
					primeCounter++;
				}
				else
					myDrawText(x,y,size,str,whiteColor,backGround);
			}
			else
			{
				if(IsPrime(number))
				{
					myDrawText(x,y,size,str,blueColor,backGround);
					cornerCounter++;
					primeCounter++;
					cornerprimeCounter++;
				}
				else
				{
					myDrawText(x,y,size,str,whiteColor,backGround);
					cornerCounter++;
				}
			}
			
			if(number==n)
				spiralComplete = true;
		}
		
		times++;
	}
	
	//code for printing the required statistics
	int result;
	
	char stat[100] = "% of numbers that lie on corners: ";
	char value[10];
	myDrawText(550,200,size,stat,whiteColor,backGround);
	result = (cornerCounter*100)/n;
	cout<< result;
	convertToStr(result,value);
	myDrawText(770,200,size,value,whiteColor,backGround);
	
	char stat2[100] = "% of prime numbers that lie on the corners: ";
	myDrawText(550,220,size,stat2,whiteColor,backGround);
	result = (cornerprimeCounter*100)/primeCounter;
	convertToStr(result,value);
	myDrawText(840,220,size,value,whiteColor,backGround);
	
	char stat3[100] = "% of numbers that lie on corners and are prime numbers: ";
	myDrawText(550,240,size,stat3,whiteColor,backGround);
	result = (cornerprimeCounter*100)/cornerCounter;
	convertToStr(result,value);
	myDrawText(925,240,size,value,whiteColor,backGround);
}

int main()
{
	int n;
	
	cout<< "Enter a number to generate spiral: ";
	cin>> n;
	
	//function call
	drawSpiral(n);
}
