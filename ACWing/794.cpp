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

vector<int> div(vector<int> a, int b, int &r)
{
    vector<int> res;
    r = 0;
    for (int i = a.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + a[i];
        res.push_back(r / b);
        r %= b;
    }
    reverse(res.begin(), res.end());
    while (res.size() > 1 and res.back() == 0) res.pop_back ();

    return res;
}

int main ()
{
    string as;
    vector<int> a;
    int b;
    
    cin >> as;
    cin >> b;
    
    for (int i = as.size() - 1; i >= 0; i --) a.push_back(as[i] - '0');

    int r = 0;
    vector<int> res = div(a, b, r); 
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
    }
    cout << endl;
    cout << r << endl;

    return 0;
}