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

int n;

vector < pair<int,int> > prime_fact (int x)
{
    vector < pair<int,int> > res;
    for (int i = 2; i <= x / i; i++)
    {
        int s = 0;
        while (x % i == 0)
        {
            x /= i;
            s ++;
        }
        if (s > 0)
        {
            res.push_back ({i, s});           
        }
    }
    if (x > 1)
    {
        res.push_back ({x, 1});
    }

    return res;
}

int main ()
{
    n = Reader::read();

    while (n --)
    {
        int a = Reader::read();
        vector < pair<int,int> > res = prime_fact (a);
        
        for (int i = 0; i < res.size (); i++)
        {
            cout << res[i].first << " " << res[i].second << endl;
        }
        cout << endl;
    }

    return 0;
}