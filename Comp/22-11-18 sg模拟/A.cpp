#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 10005;
int n;

int len;
int cur[maxn];

inline void mul2 ()
{
	int flag = 0;
	for (int i = 0; i <= len; i--)
	{
		int now = (cur[i] - '0') * 2 + flag;
		cur[i] = now % 10 + '0';
		flag = now / 10;
	}
}

inline void add1 ()
{
	int flag = 0;
	for (int i = strlen (cur) - 1; i >= 0; i--)
	{
		int now = (cur[i] - '0') + 1 + flag;
		cur[i] = now % 10 + '0';
		flag = now / 10;
	}
} 

int main ()
{
	cin >> n;
	
	for (int i = 2; i <= n; i ++)
	{
		// *= 2
		mul2 ();
		add1 ();
	}
	
	mul2 ();
	
	int start = 0;
	while (cur[start] == '0')
	{
		start ++;
	}	
	
	for (int i = start; i < strlen (cur); i++)
	{
		cout << cur[i];	
	}
	cout << endl;
	
	return 0;
}

