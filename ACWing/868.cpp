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
int primes[maxn], cnt;
bool is_prime[maxn];

void get_prime (int n)
{
    memset (is_prime, 1, sizeof (is_prime));
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            primes[++cnt] = i;
        }
        for (int j = 1; primes[j] <= n / i; j++)
        {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0)
            {
                break;
            }
        }
    }
}

int main ()
{
    int n = Reader::read();

    get_prime (n);

    cout << cnt << endl;
    return 0;
}