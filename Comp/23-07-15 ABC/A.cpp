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

const int maxn = 100005;

int n, p, q;
int a[maxn];

int main ()
{

	cin >> n >> p >> q;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	int res = p;
		
	for (int i = 1; i <= n; i++)
	{
		res = min (res, a[i] + q);
	}
	
	cout << res << endl;

	return 0;
}

