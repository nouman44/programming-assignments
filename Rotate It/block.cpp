
#include <iostream>
#include <fstream>
#include <math.h>
#include "myconsole.h"

using namespace std;

int** Allocate2DArray()
{
	int i;

	int **block = new int*[3];

	for (i = 0;i < 3;i++)
	{
		block[i] = new int[3];
	}

	return block;
}

void RotateBlockA(int **block)
{
	int temp;

	temp = block[0][0];
	block[0][0] = block[1][0];
	block[1][0] = block[1][1];
	block[1][1] = block[0][1];
	block[0][1] = temp;
}

void RotateBlockB(int **block)
{
	int temp;

	temp = block[0][1];
	block[0][1] = block[1][1];
	block[1][1] = block[1][2];
	block[1][2] = block[0][2];
	block[0][2] = temp;
}

void RotateBlockC(int **block)
{
	int temp;

	temp = block[1][0];
	block[1][0] = block[2][0];
	block[2][0] = block[2][1];
	block[2][1] = block[1][1];
	block[1][1] = temp;
}

void RotateBlockD(int **block)
{
	int temp;

	temp = block[1][1];
	block[1][1] = block[2][1];
	block[2][1] = block[2][2];
	block[2][2] = block[1][2];
	block[1][2] = temp;
}

int*** AllocateLevelArray(int level)
{
	int i;
	int ***levelArr;

	int size = pow(4, level);

	levelArr = new int**[size];

	for (i = 0;i < size;i++)
	{
		levelArr[i] = Allocate2DArray();
	}

	return levelArr;
}

int*** FillLevel0()
{
	int level = 0;
	int ***level0 = AllocateLevelArray(level);

	int i, j, num;
	ifstream inputStream("sampleInput.txt");

	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			inputStream >> num;
			level0[level][i][j] = num;
		}
	}

	return level0;
}

int*** FillLevel1(int ***level0)
{
	int ***level1 = AllocateLevelArray(1);

	int i, j, k = 0;
	int prevLevel = 0;
	int times = 4;

	for (i = 0;i < times;i++)
	{
		for (j = 0;j < 3;j++)
		{
			for (k = 0;k < 3;k++)
			{
				level1[i][j][k] = level0[prevLevel][j][k];
			}
		}
	}

	i = 0;
	RotateBlockA(level1[i]);
	i++;
	RotateBlockB(level1[i]);
	i++;
	RotateBlockC(level1[i]);
	i++;
	RotateBlockD(level1[i]);

	return level1;
}

int*** FillLevel2(int ***level1)
{
	int ***level2 = AllocateLevelArray(2);

	int i, j, k = 0;
	int prevLevel = 0;
	int times = 4;
	int counter = 0;

	for (i = 0;i < times;i++)
	{
		for (j = 0;j < 3;j++)
		{
			for (k = 0;k < 3;k++)
			{
				level2[counter][j][k] = level1[i][j][k];
			}
		}

		RotateBlockA(level2[counter]);
		counter++;
	}

	for (i = 0;i < times;i++)
	{
		for (j = 0;j < 3;j++)
		{
			for (k = 0;k < 3;k++)
			{
				level2[counter][j][k] = level1[i][j][k];
			}
		}

		RotateBlockB(level2[counter]);
		counter++;
	}

	for (i = 0;i < times;i++)
	{
		for (j = 0;j < 3;j++)
		{
			for (k = 0;k < 3;k++)
			{
				level2[counter][j][k] = level1[i][j][k];
			}
		}

		RotateBlockC(level2[counter]);
		counter++;
	}

	for (i = 0;i < times;i++)
	{
		for (j = 0;j < 3;j++)
		{
			for (k = 0;k < 3;k++)
			{
				level2[counter][j][k] = level1[i][j][k];
			}
		}

		RotateBlockD(level2[counter]);
		counter++;
	}

	return level2;
}

void DisplayLevels(int ***level0, int ***level1, int ***level2)
{
	ClearScreen();
	
	int x = 0;
	int y = 1;
	int i,j,k;
	int counter0 = 1,counter1 = 4,counter2 = 16;
	
	PlaceCursor(x,y);
	cout << "LEVEL 0:";
	y = y + 2;
	PlaceCursor(x,y);
	for (i = 0;i < counter0;i++)
	{
		for (j = 0;j < 3;j++)
		{
			for (k = 0;k < 3;k++)
			{
				cout << level0[i][j][k] << " ";
			}
			y++;
			PlaceCursor(x,y);
		}
	}
	
	y = y + 2;
	PlaceCursor(x,y);
	cout << "LEVEL 1:";
	y = y + 2;
	PlaceCursor(x,y);
	for (i = 0;i < counter1;i++)
	{
		for (j = 0;j < 3;j++)
		{
			for (k = 0;k < 3;k++)
			{
				cout << level1[i][j][k] << " ";
			}
			y++;
			PlaceCursor(x,y);
		}
		y = y - 3;
		x = x + 8;
		PlaceCursor(x,y);
	}
	
	y = y + 5;
	x = 0;
	PlaceCursor(x,y);
	cout << "LEVEL 2:";
	y = y + 2;
	PlaceCursor(x,y);
	for (i = 0;i < counter2;i++)
	{
		for (j = 0;j < 3;j++)
		{
			for (k = 0;k < 3;k++)
			{
				cout << level2[i][j][k] << " ";
			}
			y++;
			PlaceCursor(x,y);
		}
		if((i+1)%4==0)
		{
			x = 0;
			y = y + 2;
		}
		else
		{
			x = x + 8;
			y = y - 3;
		}
		PlaceCursor(x,y);
	}
	
}

int main()
{
	int ***level0 = FillLevel0();
	int ***level1 = FillLevel1(level0);
	int ***level2 = FillLevel2(level1);

	DisplayLevels(level0,level1,level2);

    return 0;
}

