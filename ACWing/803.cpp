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

int n;
vector<PII> ranges;

inline void merge (vector<PII>& segs)
{
    vector<PII> res;
    sort (segs.begin(), segs.end());
    
    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
    {
        if (seg.first > ed)
        {
            if (st != -2e9) res.push_back ({st, ed});
            st = seg.first;
            ed = seg.second;
        }
        else
        {
            ed = max (ed, seg.second);
        }
    }
    if (st != -2e9) res.push_back ({st, ed});

    segs = res;
}

int main ()
{
    n = Reader::read();
    for (int i = 1; i <= n; i++)
    {
        int l = Reader::read();
        int r = Reader::read();
        ranges.push_back ({l, r});
    }    

    merge(ranges);

    cout << ranges.size() << endl;

    return 0;
}