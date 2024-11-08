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

typedef long long ll;

int popcount (ll x)
{
	int cnt = 0;
	while (x)
	{
		if (x % 2 == 1) cnt++;
		x /= 2; 
	}
	return cnt;
}

ll lowbit (ll x)
{
	return x & (-x);
}

int T;

int main ()
{
	cin >> T;
	while (T--)
	{
		ll x;
		cin >> x;
		if (popcount (x) >= 3) cout << "No,Commander" << endl;
		else if (popcount (x) == 2) cout << x + lowbit(x) << endl;
		else cout << x + 1 << endl;
	}
	
	return 0;
}

