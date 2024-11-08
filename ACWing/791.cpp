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

vector<int> Add(vector<int> a, vector<int> b)
{
    if (a.size() < b.size())
        swap(a, b);

    vector<int> res;

    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i];
        if (i < b.size())
            t += b[i];
        res.push_back(t % 10);
        t /= 10;
    }
    if (t)
        res.push_back(t);
    return res;
}

int main()
{
    string a_s, b_s;
    cin >> a_s >> b_s;
    vector<int> a;
    vector<int> b;

    for (int i = a_s.size() - 1; i >= 0; i--)
        a.push_back(a_s[i] - '0');
    for (int i = b_s.size() - 1; i >= 0; i--)
        b.push_back(b_s[i] - '0');

    vector<int> res = Add(a, b);
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
    }
    cout << endl;

    return 0;
}