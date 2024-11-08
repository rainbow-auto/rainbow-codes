#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;

string p, q, r;

ll get_num (string a, int x)
{
	ll res = 0;
	for (int i = 0; i < a.size(); i++) res = res * x + int(a[i] - '0');
	return res;
}

int main ()
{
	fastread
	
	cin >> p >> q >> r;
	
	int maxx = 0;
	for (int i = 0; i < p.size(); i++) maxx = max (p[i] - '0', maxx); 
	for (int i = 0; i < q.size(); i++) maxx = max (q[i] - '0', maxx); 
	for (int i = 0; i < r.size(); i++) maxx = max (r[i] - '0', maxx); 
	
	for (int i = maxx + 1; i <= 16; i++)
	{
		if (get_num (p, i) * get_num (q, i) == get_num (r, i))
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	
	return 0;
}
