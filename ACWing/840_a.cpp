/*
    本题非正解做法
    (set乱搞)
*/
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

int n;
set<int> s;

int main ()
{
    n = Reader::read();
    for (int i = 1; i <= n; i++)
    {
        char op;
        cin >> op;
        int x = Reader::read();

        if (op == 'I')
        {
            s.insert(x);
        }
        else if (op == 'Q')
        {
            if (s.count(x)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }   
    return 0;
}