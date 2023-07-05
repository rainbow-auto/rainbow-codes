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

int n, m;
priority_queue<int, vector<int>, greater<int> > q;

int main ()
{
    n = Reader::read();
    m = Reader::read();

    for (int i = 1; i <= n; i++)
    {
        int now = Reader::read();
        q.push(now);
    }

    for (int i = 1; i <= m; i++)
    {
        cout << q.top() << " ";
        q.pop();
    }
    
    return 0;
}