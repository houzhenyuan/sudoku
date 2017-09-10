// sudokuProject.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <fstream> 
#include<stdlib.h>

using namespace std;

ofstream myfile("sudoku.txt");

int Data[10][10];
int Count = 0;

int check(int x, int y, int m)

{
	int x0, y0;
	for (int i = 0; i <= 7; i++)
	{
		if (Data[x][(y + i) % 9 + 1] == m)
		{
			return false;
		}
		if (Data[(x + i) % 9 + 1][y] == m)
		{
			return false;
		}
	}
	if ((double)x / 3 <= 1)  x0 = 0;
	if ((double)x / 3 >1 && (double)x / 3 <= 2) x0 = 1;
	if ((double)x / 3 >2 && (double)x / 3 <= 3) x0 = 2;
	if ((double)y / 3 <= 1) y0 = 0;
	if ((double)y / 3 >1 && (double)y / 3 <= 2) y0 = 1;
	if ((double)y / 3 >2 && (double)y / 3 <= 3) y0 = 2;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (Data[(x0 * 3) + i][(y0 * 3) + j] == m)
				return false;
		}
	}
	return true;
}

void dfs(int x, int y, int n)
{
	if (Count >= n)
	{
		return;
	}
	if (x>9)
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				myfile << Data[i][j] << " ";
				//cout << Data[i][j] << " ";
			}
			myfile << endl;
		}
		myfile << endl;
		Count++;
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (check(x, y, i))
		{
			Data[x][y] = i;
			if (y >= 9) dfs(x + 1, 1, n);
			else dfs(x, y + 1, n);
		}
		if (y >= 9) Data[x + 1][1] = 0;
		else Data[x][y + 1] = 0;
	}
}

int main(int argc, char ** argv)
{

	Data[1][1] = 1;
	int n;
	if (*argv[2] <= '0' || *argv[2] > '9')
	{
		cout << "Input error" << endl;
	}
	else
	{
		n = atoi(argv[2]);
		dfs(1, 2, n);
	}
	myfile.close();
	return 0;
}