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

const int maxn = 100005;

typedef long long ll;
int n, m, q;

ll a[maxn], b[maxn];

int main ()
{
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout); 
	
	cin >> n >> m >> q;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
	}
	
	while (q--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		ll ans = -0x7f7f7f7f7f7f7f7f;
		
		for (int i = l1; i <= r1; i++)
		{
			ll now = 0x7f7f7f7f7f7f7f7f;
			for (int j = l2; j <= r2; j++)
			{
				now = min (now, a[i] * b[j]);
			}
			ans = max (ans, now);
		}
		cout << ans << endl;
	}
	
	fclose (stdin);
	fclose (stdout); 
	
	return 0;
}

