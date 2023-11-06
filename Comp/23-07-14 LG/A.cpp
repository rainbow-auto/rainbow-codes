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

long long a, b, c;

int main ()
{
	cin >> a >> b >> c;
	
	if (a + b + c <= 100 and b % 5 == 0 and c % 7 == 0 and a - b > b - c) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}

