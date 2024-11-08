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


bool solve ()
{
	int top = 0;
	stack<int> s;
	
	for (int i = 1; i <= n; i++)
	{
		while (s.empty() or s.top() < a[i]) 
		{
			s.push(++top);
		}
		
		if (s.top() == a[i])
		{
			s.pop();
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main ()
{
	fastread
	
	while (true)
	{
		cin >> n;
		if (n == 0) break;	
		
		while (true)
		{
			bool flag = false;
			for (int i = 1; i <= n; i++)
			{
				cin >> a[i];
				if (a[i] == 0)
				{
					flag = true;
					break;
				}	
			}	
			if (flag) break;
		
			if (solve ())
			{
				cout << "Yes" << endl;	
			}		
			else
			{
				cout << "No" << endl;
			}
		}	
		cout << endl;
	}	
		
	return 0;
}