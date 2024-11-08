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

int exgcd (int a, int b, int& x, int& y)
{
    if (not b)
    {
        x = 1, y = 0;
        return a;
    }
    int res = exgcd (b, a % b, y, x);
    y -= a / b * x;
    return res;
}

int main ()
{
    int n = Reader::read();

    while (n --)
    {
        int a = Reader::read();
        int b = Reader::read();
        int x, y;
        exgcd (a, b, x, y);
        cout << x << " " << y << endl;
    }
    return 0;
}