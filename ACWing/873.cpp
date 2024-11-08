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

int phi (int x)
{
    int res = x;
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            while (x % i == 0) x /= i;
            res = res / i * (i - 1);
        }
    }
    if (x > 1) res = res / x * (x - 1);
    return res;
}

int main ()
{
    int n = Reader::read();
    for (int i = 1; i <= n; i++)
    {
        int x = Reader::read();
        cout << phi (x) << endl;
    }

    return 0;
}