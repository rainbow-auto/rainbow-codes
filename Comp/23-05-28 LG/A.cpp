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

long long n, k, a, b;

int main ()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
	
		a = k;
		b = n - k;
		if (k % (n - k) != k)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << a << " " << b << endl;
		}	
	} 
	
	return 0;
}

