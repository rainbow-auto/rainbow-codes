#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 10005;
int n;
int a[maxn];
string s;

int solve (int l, int r)
{
	if (l == r)
	{
		if (a[l] == 0)
		{
			s += 'B';
			return 0;
		}
		else
		{
			s += 'I';
			return 1;
		}
	}
	
	int res = 0;	
	int mid = (l + r) >> 1;
	
	res += solve (l, mid);
	res += solve (mid + 1, r);
	
	if (res == 0)
	{
		s += 'B';
	}
	else if (res == r - l + 1)
	{
		s += 'I';
	}
	else
	{
		s += 'F';			
	}
	
	return res;
}

int main ()
{
	fastread
		
	cin >> n;
	
	n = 1 << n;
	
	for (int i = 1; i <= n; i++)
	{
		char ch;
		cin >> ch;
		if (ch == '0')
		{
			a[i] = 0;
		}
		else
		{
			a[i] = 1;
		}
	}
	
	solve (1, n);
	
	cout << s << endl;
		
	return 0;
}