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
#include <unordered_map>

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

const int mod = 1e9 + 7;

unordered_map <int, int> h;
void prime_fact (int x)
{
    for (int i = 2; i <= x / i; i++)
    {
        while (x % i == 0)
        {
            h[i]++;
            x /= i;
        }
    }
    if (x > 1) h[x] ++;
}

int main ()
{
    int n = Reader::read();
    while (n --)
    {
        int x = Reader::read();
        
        prime_fact (x);
    }

    long long ans = 1;
    for (auto x : h)
    {
        long long t = 1;
        for (int i = 1; i <= x.second; i++)
        {
            t = (t * x.first + 1) % mod;
        }
        ans = (ans * t) % mod;
    }

    cout << ans << endl;

    return 0;
}