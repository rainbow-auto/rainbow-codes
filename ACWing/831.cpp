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

const int maxn = 1000005;
int nxt[maxn];

int n, m;
char s[maxn];
char p[maxn];

int main ()
{
    m = Reader::read();
    for (int i = 1; i <= m; i++) cin >> p[i]; 
    
    n = Reader::read();
    for (int i = 1; i <= n; i++) cin >> s[i];

    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j and p[i] != p[j + 1]) j = nxt[j];
        if (p[i] == p[j + 1]) j++;
        nxt[i] = j;
    }

    for (int i = 1, j = 0; i <= n; i++)
    {   
        while (j and s[i] != p[j + 1]) j = nxt[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m)
        {
            cout << i - m  << " ";
            j = nxt[j];
        }
    }

    return 0; 
}