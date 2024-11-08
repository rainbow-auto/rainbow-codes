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

vector<int> get_divisors (int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            res.push_back (i);
            if (i != x / i) res.push_back (x / i); // i * i != n
        }
    }
    sort (res.begin(), res.end());
    return res;
}

int main ()
{
    int n = Reader::read();

    while (n --)
    {
        int x = Reader::read();
        vector<int> res = get_divisors(x);

        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";            
        }
        cout << endl;
    }

    return 0;
}