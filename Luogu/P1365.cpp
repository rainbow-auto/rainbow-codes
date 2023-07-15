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

const int maxn = 300005; 

int n;

double ans;
double x1;

/*
(x + 1) ^ 2 = x ^ 2 + 2 * x + 1
*/

int main ()
{
	fastread
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		char now; cin >> now;
		double p;
		if (now == 'x') p = 0;
		if (now == 'o') p = 1;
		if (now == '?') p = 0.5; 
	
		ans += (2 * x1 + 1) * p;
		x1 = (x1 + 1) * p;
	}
	
	printf ("%.4lf", ans);
		
	return 0;
}
