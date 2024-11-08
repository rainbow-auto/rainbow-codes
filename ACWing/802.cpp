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

typedef pair<int, int> PII;

const int maxn = 300005;
int s[maxn];
vector<PII> add;
vector<PII> query;
vector<int> a;

int n, m;

int find (int x)
{
    int l = 0, r = a.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;
}

int main ()
{
    n = Reader::read();
    m = Reader::read();
    for (int i = 1; i <= n; i++)
    {
        int x = Reader::read();
        int c = Reader::read();
        add.push_back ({x, c});
        a.push_back (x);
    }

    for (int i = 1; i <= m; i++)
    {
        int l = Reader::read();
        int r = Reader::read();
        query.push_back ({l, r});
        a.push_back (l);
        a.push_back (r);
    }

    sort (a.begin(), a.end());
    a.erase (unique(a.begin(), a.end()), a.end());

    for (auto item : add)
    {
        int x = find (item.first);
        s[x] += item.second;
    }

    for (int i = 1; i <= a.size(); i++) s[i] += s[i - 1];

    for (auto item : query)
    {
        int l = find(item.first);
        int r = find(item.second);
        cout << s[r] - s[l - 1] << endl; 
    }

    return 0;
}