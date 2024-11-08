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

int siz[maxn];
int fa[maxn];
int find (int x)
{
    if (fa[x] != x)
    {
        return fa[x] = find (fa[x]);
    }
    return fa[x];
}

inline void init ()
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        siz[i] = 1;
    }
}

int main ()
{
    n = Reader::read();
    m = Reader::read();

    init();

    for (int i = 1; i <= m; i++)
    {
        string op;
        cin >> op;

        if (op == "C")
        {
            int a = Reader::read();
            int b = Reader::read();
            
            int a_root = find(a);
            int b_root = find(b);
            if (a_root == b_root) continue;

            fa[a_root] = b_root;
            siz[b_root] += siz[a_root];
        }
        else if (op == "Q1")
        {
            int a = Reader::read();
            int b = Reader::read();
            
            int a_root = find(a);
            int b_root = find(b);
            if (a_root == b_root)
            {
                cout << "Yes" << endl;
            }
            else 
            {
                cout << "No" << endl;
            }
        }
        else if (op == "Q2")
        {
            int a = Reader::read();
            
            int a_root = find(a);
            cout << siz[a_root] << endl;
        }
    }

    return 0;
}