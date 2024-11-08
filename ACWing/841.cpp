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

const int maxn = 100005;

typedef unsigned long long ull;
const ull mod = 13331;

ull p[maxn]; // mod ^ i
ull h[maxn]; // hash

string s;
int n, m;

inline void init ()
{
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        h[i] = h[i - 1] * mod + s[i - 1]; // s 下标从0开始
        p[i] = p[i - 1] * mod;
    }
}

inline ull hash_val (int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];  
}

int main ()
{
    n = Reader::read();
    m = Reader::read();
    cin >> s;
    init ();

    while (m --)
    {
        int l1 = Reader::read();
        int r1 = Reader::read();
        int l2 = Reader::read();
        int r2 = Reader::read();
        if (hash_val (l1, r1) == hash_val (l2, r2))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;            
        }
    }

    return 0;
}