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
int a[maxn];

stack <int> stk;

int main ()
{
    n = Reader::read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = Reader::read();
    }    

    for (int i = 1; i <= n; i++)
    {
        while (not stk.empty() and a[stk.top()] >= a[i]) stk.pop();
        if (stk.empty ()) cout << "-1 "; 
        else cout << a[stk.top()] << " ";
        stk.push(i);
    }

    return 0;
}