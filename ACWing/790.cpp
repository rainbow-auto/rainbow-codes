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

double eps = 1e-10;
double x;

int main ()
{
    x = Reader::read();
    double l = -1000, r = 1000;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid <= x) l = mid;
        else r = mid;
    }
    printf ("%lf", l);
    
    return 0;
}