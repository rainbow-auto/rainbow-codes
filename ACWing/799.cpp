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

namespace Reader {
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

int t[maxn];

int main ()
{
    n = Reader::read();
    for (int i = 1; i <= n; i++) 
    {
        a[i] = Reader::read();
    }   

    int ans = 0;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        t[a[i]] ++;
        while (j < i and t[a[i]] > 1)
        {
            t[a[j]] --;
            j ++;
        }
        ans = max (i - j + 1, ans);        
    }

    cout << ans << endl;

    return 0;
}