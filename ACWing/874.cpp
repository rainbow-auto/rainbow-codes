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

const int maxn = 1000005;
typedef long long ll;

int phi[maxn];
int primes[maxn], cnt;
bool st[maxn];


void get_phi (int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (not st[i]) 
        {
            primes[++cnt] = i;
            phi[i] = i - 1; // 是质数的话1~i-1全部与其互质
        }
        for (int j = 1; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
} 

int main ()
{
    int n = Reader::read();
    get_phi (n);

    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += phi[i];
    }
    cout << res << endl;

    return 0;
}