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

namespace Reader
{
    int read()
    {
        char c = getchar();
        int x = 0, flag = 1;
        while (not isdigit(c))
        {
            if (c == '-')
                flag = -1;
            c = getchar();
        }
        while (isdigit(c))
        {
            x = x * 10 + c - '0';
            c = getchar();
        }
        return x * flag;
    }
}

bool operator < (vector<int> a, vector<int> b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i --)
    {
        if (a[i] != b[i])
        {
            return a[i] < b[i];   
        }
    }
    return false; // a == b
}

vector<int> Sub(vector<int> a, vector<int> b)
{
    bool flag = false;
    if (a < b)
    {
        flag = true;
        swap (a, b);
    }
    
    vector<int> res;

    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t = a[i] - t;
        if (i < b.size()) t -= b[i];
        res.push_back((t + 10) % 10);
        if (t < 0)
        {
            t = 1;
        }
        else
        {
            t = 0;
        }
    }

    while (res.size() > 1 and res.back() == 0) res.pop_back ();
    if (flag)
    {
        res.push_back(-1); // 负数 -1
    }
    else 
    {
        res.push_back(0); // 正数 0
    }
    return res;
}

int main()
{
    string as, bs;
    cin >> as >> bs;

    vector<int> a;
    vector<int> b;
    for (int i = as.size() - 1; i >= 0; i--) a.push_back(as[i] - '0');     
    for (int i = bs.size() - 1; i >= 0; i--) b.push_back(bs[i] - '0');     
    
    vector<int> res = Sub (a, b);
    if (res.back() == -1)
    {
        cout << '-';        
    }
    res.pop_back();

    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
    }
    cout << endl;

    return 0;
}