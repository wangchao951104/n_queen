#include<iostream>
using namespace std;

static int eq[8] = {0}, count = 0;

void print() {
	for(int i = 0; i < 8; i++)
	{
		int j;
		for(j = 0; j < eq[i]; j++)
		  cout << "0";
		cout << "#";
		for(j = eq[i]+1; j < 8; j++)
		  cout << "0";
		cout << endl;
	}
	cout << "------------------------------\n";
}

bool check(int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		j = eq[i];
		if (col == j)
		  return false;
		if (row - col == i - j)
		  return false;
		if (row + col == i + j)
		  return false;
	}
	return true;
}

void eight_queen(int row)
{
	if (row == 8)
	{
		count++;
		print();
		return;
	}
	int col;
	for (col = 0; col < 8; col++)
	{
		if(check(row, col))
		{
			eq[row] = col;
			eight_queen(row+1);
			eq[row] = 0;
		}
	}
}

int main()
{
	eight_queen(0);
	cout << "total=" << count << endl;
}

