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

int n = 1;
int k, m;

int main ()
{
	cin >> k >> m;
	
	int now = 1;
	
	while (now % m != k)
	{
		now = now * 10 + 1;
		n ++; 
	}
	
	cout << n << endl;
	
	return 0;
}

