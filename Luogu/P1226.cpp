# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <string>
# include <map>
# include <cmath>
# include <cstring>
# include <queue>
# include <set>
# define endl "\n"
using namespace std;

typedef long long ll;

ll ksm (ll a, ll b, ll p)
{
    ll res = 1;
    for (ll base = a; b; b >>= 1, base *= base, base %= p) 
        if (b & 1) res *= base, res %= p;
    return res;
}
int main ()
{
	ll a, b, p;
	cin >> a >> b >> p;
	
	ll ans = ksm (a, b, p);
	cout << a << "^" << b << " mod " << p << "=" << ans << endl; 
	return 0;
}
