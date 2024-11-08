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

typedef unsigned long long ull;
ull ans;

ull n;

int main ()
{
	cin >> n;
	ans = n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;
	cout << ans << endl; 
	return 0;
}

