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

const int maxn = 20;

int n;
bool col[maxn];
bool lx[maxn];
bool rx[maxn];

char g[maxn][maxn];

void dfs (int nowx)
{
    if (nowx > n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << g[i][j];
            }
            cout << endl;
        }   
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (col[i]) continue;
        if (lx[nowx + i]) continue;
        if (rx[i - nowx + n]) continue;
        g[nowx][i] = 'Q';
        col[i] = lx[nowx + i] = rx[i - nowx + n] = true;
        dfs (nowx + 1);
        col[i] = lx[nowx + i] = rx[i - nowx + n] = false;
        g[nowx][i] = '.';
    }
}

int main ()
{
    n = Reader::read();
    
    for (int i =1 ; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g[i][j] = '.';
        }
    }
    
    dfs (1);

    return 0;
}