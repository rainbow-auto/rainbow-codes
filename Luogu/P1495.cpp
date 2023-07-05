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

using namespace std;

namespace Reader{
    int read ()
    {
        char c = getchar (); 
        int x = 0, flag = 1;
        while (not isdigit (c)) { if (c == '-') flag = -1; c = getchar(); }
        while (isdigit (c)) { x = x * 10 + c - '0'; c = getchar(); }
        return x * flag;
    }
}

typedef long long ll;

const int maxn = 30;
int n;
ll a[maxn];
ll b[maxn];

ll mul;

ll exgcd (ll a, ll b, ll& x, ll& y)
{
    if (not b)
    {
        x = 1, y = 0;
        return a;
    }    
    ll res = exgcd (b, a % b, y, x);
    y -= x * (a / b);
    return res;
}

ll crt ()
{
    mul = 1;
    for (int i = 1; i <= n; i++) mul *= a[i];

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll m = mul / a[i];
        ll mr = 0, y = 0;
        exgcd (m, a[i], mr, y);
        mr = mr < 0 ? mr + a[i] : mr;
        ans += b[i] * m * mr; 
    }
    return ans % mul;
}

int main ()
{
    n = Reader::read();

    for (int i = 1; i <= n; i++)
    {
        a[i] = Reader::read();
        b[i] = Reader::read();
    }

    cout << crt () << endl;

    return 0;
}