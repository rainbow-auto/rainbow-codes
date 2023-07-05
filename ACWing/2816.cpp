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
int a[maxn];
int b[maxn];
int n, m;

int main ()
{
    n = Reader::read();
    m = Reader::read();
    for (int i = 1; i <= n; i++) a[i] = Reader::read();
    for (int i = 1; i <= m; i++) b[i] = Reader::read();

    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        while (j <= m and a[i] != b[j])
        {
            j++;
        }
        if (j > m)
        {
            cout << "No" << endl;
            return 0;
        }
        j ++;
    }
    cout << "Yes" << endl;

    return 0;
}