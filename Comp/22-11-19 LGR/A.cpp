#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

const int maxn = 100005;
int T;
int n;

int xs[maxn], ys[maxn];

int main ()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		int xsum = 0;
		int ysum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> xs[i] >> ys[i];
			xsum += xs[i];
			ysum += ys[i];
		}	
		int xbar = xsum / n;
		int ybar = ysum / n;
		
		sort (xs + 1, xs + n + 1);
		sort (ys + 1, ys + n + 1);
		
		if (ybar > min (ys[n / 2 + 1], ys[n / 2]) and ybar < max (ys[n / 2 + 1], ys[n / 2]))
		{
			cout << 2 << endl;
			continue;
		}
		if (xbar > min (xs[n / 2 + 1], xs[n / 2]) and xbar < max (xs[n / 2 + 1], xs[n / 2]))
		{
			cout << 2 << endl; 
			continue;
		}
		cout << 3 << endl;
	}
	return 0;
}

