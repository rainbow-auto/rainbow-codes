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

int m;

int head;
int cnt;
int nxt[maxn];
int val[maxn];

inline void add_to_head (int x)
{
    cnt ++;
    nxt[cnt] = head;
    val[cnt] = x;
    head = cnt;
}

inline void add (int k, int x)
{
    cnt ++;
    nxt[cnt] = nxt[k];
    val[cnt] = x;
    nxt[k] = cnt;
}

inline void remove (int k)
{
    nxt[k] = nxt[nxt[k]];
}

int main ()
{
    cin >> m;
    head = -1;
    for (int i = 1; i <= m; i++)
    {
        char op;
        cin >> op;
        if (op == 'H')
        {
            int x = Reader::read();
            add_to_head (x);
        }
        if (op == 'D')
        {
            int k = Reader::read();
            remove(k);
        }
        if (op == 'I')
        {
            int k = Reader::read();
            int x = Reader::read();
            add (k, x);
        }
    }

    int curr = head;
    while (curr != -1)
    {
        cout << val[curr] << " ";
        curr = nxt[curr];
    }

    return 0;
}