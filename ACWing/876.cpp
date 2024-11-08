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
ll ksm (ll a, ll b, ll p)
{
    ll res = 1;
    ll base = a;
    while (b)
    {
        if (b & 1)
        {
            res *= base;
            res %= p;
        }
        base *= base;
        base %= p;
        b >>= 1;
    }
    return res;
}

int main ()
{
    int n = Reader::read();
    while (n --)
    {
        int a = Reader::read();
        int p = Reader::read();
        if (a % p == 0)
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << ksm (a, p - 2, p) << endl;
        }
    }

    return 0;
}