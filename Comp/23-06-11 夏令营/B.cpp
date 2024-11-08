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

int n, m;
ll x;

int main ()
{
	cin >> n >> m;
	
	if (n <= 2)
	{
		int temp;
		cin >> temp >> temp >> x;
		cout << x << endl;
	}		
	else
	{
		cout << -1 << endl;
	}
		
	return 0;
}

