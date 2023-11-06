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

typedef unsigned long long ll;

int T;

int solve (ll n)
{
	int tot = 0;
	while (n)
	{
		tot += n % 3;
		n /= 3;	
	}
	return tot;
}

int main ()
{
	cin >> T;
	
	while (T--)
	{
		ll n, k;
		cin >> n >> k;
		
		if (solve (n) == k) cout << "Yes" << endl;
		else cout << "No" << endl; 
	}
	
	return 0;
}

