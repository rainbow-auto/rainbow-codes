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

const int maxn = 32 * 100005;
int trie[maxn][2];
bool end[maxn];
int id;

int n;

inline void insert (int x)
{
    int now = 0;
    for (int i = 31; i >= 0; i--)
    {
        int v = (x >> i) & 1;
        if (not trie[now][v])
        {
            id++;
            trie[now][v] = id;
        }
        now = trie[now][v];
    }
}

inline int query (int x)
{
    int res = 0;
    int now = 0;
    for (int i = 31; i >= 0; i--)
    {
        int v = (x >> i) & 1;
        if (trie[now][!v])
        {
            now = trie[now][!v];
            res = res << 1 | !v;
        }
        else 
        {
            now = trie[now][v];
            res = res << 1 | v;
        }
    }
    return res;
}

int main ()
{
    n = Reader::read();
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int now = Reader::read();
        insert (now);
        res = max (res, query(now) ^ now);
    }   

    cout << res << endl;

    return 0;
}