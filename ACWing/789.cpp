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

int n, q;
int a[maxn];

int main ()
{
    n = Reader::read();
    q = Reader::read();
    for (int i = 0; i <= n - 1; i++)
    {
        a[i] = Reader::read();
    }

    for (int i = 1; i <= q; i++)
    {
        int now = Reader::read();
        
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (a[mid] >= now)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (a[l] != now)
        {
            cout << "-1 -1" << endl;
            continue;
        }
        cout << l << " ";

        l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (a[mid] <= now)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << l << endl;
    }

    return 0;
}