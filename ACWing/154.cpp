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
int n, k;
int a[maxn];

deque<int> q;

int main ()
{
    n = Reader::read();
    k = Reader::read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = Reader::read();
    }

    q.clear();
    for (int i = 1; i <= n; i++)
    {
        if (not q.empty() and i - q.back() + 1 > k) q.pop_back();
        while (not q.empty() and a[q.front()] >= a[i]) q.pop_front();
        q.push_front(i);
        
        if (i >= k)
        {
            cout << a[q.back ()] << " ";
        }
    }

    cout << endl;

    q.clear();
    for (int i = 1; i <= n; i++)
    {
        if (not q.empty() and i - q.back() + 1 > k) q.pop_back();
        while (not q.empty() and a[q.front()] <= a[i]) q.pop_front();
        q.push_front(i);

        if (i >= k)
        {
            cout << a[q.back ()] << " ";
        }
    }

    return 0;
}