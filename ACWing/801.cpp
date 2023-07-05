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

const int maxn = 100005;
int n;
int a[maxn];

inline int lowbit(int x)
{
    return x & (-x);
}

int main ()
{   
    n = Reader::read();
    for (int i = 1; i <= n; i++)
    {
        int now = Reader::read();
        int ans = 0;
        while (now)
        {
            now -= lowbit(now);
            ans ++;
        }
        cout << ans << " ";
    } 
    return 0;
}