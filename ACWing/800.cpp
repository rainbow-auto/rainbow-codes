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
int n, m;
int a[maxn];
int b[maxn];

int x;

int main ()
{
    n = Reader::read();
    m = Reader::read();
    x = Reader::read();

    for (int i = 1; i <= n; i++) a[i] = Reader::read();
    for (int i = 1; i <= m; i++) b[i] = Reader::read();

    for (int i = 1, j = m; i <= n; i++)
    {
        while (a[i] + b[j] > x)
        {
            j --;
        }
        if (a[i] + b[j] == x)
        {
            cout << i - 1<< " " << j - 1 << endl; // 下标从0开始
            break;
        }
    }

    return 0;
}