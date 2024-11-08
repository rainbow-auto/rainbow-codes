#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

typedef long long ll;

int T;

int main ()
{
	freopen ("decode.in", "r", stdin);
	freopen ("decode.out", "w", stdout);
	cin >> T;
	
	while (T--)
	{
		ll n, e, d;
		cin >> n >> e >> d;
		ll a = 1;
		ll b = e * d - n - 2;
		ll c = n;
		ll delta = b * b - 4 * a * c;
		if (delta < 0)
		{
			cout << "NO" << endl;
			continue; 
		}
		
		ll sd = sqrt (delta);
		if (sd * sd != delta)
		{
			cout << "NO" << endl;
			continue;
		}
		
		ll p = -b - sd; p /= 2 * a;
		ll q = -b + sd; q /= 2 * a;
		cout << p << " " << q << endl;
	}			
	return 0;
}

