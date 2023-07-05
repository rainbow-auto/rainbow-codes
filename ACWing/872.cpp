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

int gcd (int a, int b)
{
    return b ? gcd (b, a % b) : a;
}

int main ()
{
    int n = Reader::read();
    
    while (n --)
    {
        int a = Reader::read();
        int b = Reader::read();
        cout << gcd(a, b) << endl;
    }
    
    return 0;
}