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

double ans;
double x1;

int main ()
{
	fastread
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		double p; cin >> p;
		
		ans += (2 * x1 + 1) * p;
		x1 = (x1 + 1) * p;
	}
	
	printf ("%.15lf", ans);	
	
	return 0;
}
