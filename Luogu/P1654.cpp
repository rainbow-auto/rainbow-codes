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

const int maxn = 100005;

int n;

double p[maxn];
double ans; 

/*

(x + 1) ^ 3 = x ^ 3 + 3 * x ^ 2 + 3 * x + 1

(x + 1) ^ 2 = x ^ 1 + 2 * x + 1

*/

double x1[maxn];
double x2[maxn];

int main ()
{
	fastread
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i]; 
		x2[i] = (x2[i - 1] + 2 * x1[i - 1] + 1)	* p[i];	
		x1[i] = (x1[i - 1] + 1) * p[i];
		ans += (3 * x2[i - 1] + 3 * x1[i - 1] + 1) * p[i]; 
	}
	
	printf ("%.1lf", ans);
	
	return 0;
}
