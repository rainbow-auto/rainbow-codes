#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>

#define endl "\n"

using namespace std;

int n, m; 

inline bool check (int k)
{
	int bak_k = k;
	
	int sum = 0;
	while (k)
	{
		int now = k % 10;
		sum += now * now * now * now;
		k /= 10;	
	} 
	if (sum == bak_k) return true;
	else return false;
}

int main ()
{
	cin >> n >> m;
	
	for (int i = n; i <= m; i++)
	{
		if (i < 1000) continue;
		if (i >= 10000) break;
		
		if (check (i))
		{
			cout << i << endl;
		}
	}
	
	return 0;
}

