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

using namespace std;

const int maxn = 100005;

int n;
int x;

int main ()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int curr;
		cin >> curr;
		x ^= curr;
	}
	
	if (x == 0)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}
	
	return 0;
}