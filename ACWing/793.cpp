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

vector<int> mul (vector<int> a, int b)
{
    vector<int> res;
    int t = 0;
    for (int i = 0; i < a.size() or t; i++)
    {
        if (i < a.size()) t += a[i] * b;
        res.push_back(t % 10);
        t /= 10;
    }

    while (res.size() > 1 and res.back() == 0) res.pop_back();
    
    return res;
}

int main ()
{
    string as;
    vector<int> a;
    int b;
    cin >> as >> b;
    
    for (int i = as.size() - 1; i >= 0; i --) a.push_back(as[i] - '0');

    vector<int> res = mul (a, b);
    for (int i = res.size() - 1; i >= 0; i --)
    {
        cout << res[i];
    }
    cout << endl;

    return 0;
}