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
int trie[maxn][26], id;
int cnt[maxn];

inline void insert (string s)
{
    int now = 0;
    for (int i = 0; i < s.size(); i ++)
    {
        int ch = s[i] - 'a';
        if (not trie[now][ch])
        {
            id ++;
            trie[now][ch] = id; 
        }
        now = trie[now][ch];
    }
    cnt[now] ++;
}

inline int query (string s)
{
    int now = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int ch = s[i] - 'a';
        if (not trie[now][ch]) return 0;
        now = trie[now][ch];
    }
    return cnt[now];
}

int main ()
{
    n = Reader::read();
    for (int i = 1; i <= n; i++)
    {
        char op;
        string s;
        cin >> op >> s;
        if (op == 'I')
        {
            insert (s);
        }
        else if (op == 'Q')
        {
            cout << query(s) << endl;
        }
    }
    return 0;
}