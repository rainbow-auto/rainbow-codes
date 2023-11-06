#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

int T;
char m[4][4];

bool check (char ch)
{
	for (int i = 1; i <= 3; i++) 
	{
		int cnt = 0;
		for (int j = 1; j <= 3; j++)
		{
			if (m[i][j] == ch) cnt ++;
		}
		if (cnt == 3) return true;
	}
	
	for (int i = 1; i <= 3; i++) 
	{
		int cnt = 0;
		for (int j = 1; j <= 3; j++)
		{
			if (m[j][i] == ch) cnt ++;
		}
		if (cnt == 3) return true;
	}
	
	if (m[1][1] == ch and m[2][2] == ch and m[3][3] == ch) return true;
	if (m[1][3] == ch and m[2][2] == ch and m[3][1] == ch) return true;
	
	return false;	
}

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	
	while (T--)
	{
		for (int i = 1; i <= 3; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				cin >> m[i][j];
			}
		}	
		
		char ch = ' ';
		if (check ('X')) 
		{
			ch = 'X';
			cout << "X" << endl;
		}
		else if (check ('+')) 
		{
			if (ch != ' ')
			{
				cout << "DRAW" << endl;
				continue;
			}
			
			ch = '+';
			cout << "+" << endl;
		}
		else if (check ('O')) 
		{
			if (ch != ' ')
			{
				cout << "DRAW" << endl;
				continue;
			}
			ch = 'O';
			cout << "O" << endl;
		}
		else 
		{
			cout << "DRAW" << endl;
		}
	}	
	
	return 0;
}

