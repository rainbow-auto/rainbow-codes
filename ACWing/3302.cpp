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

string s;

stack<char> op;
stack<int> num;

map<char, int> h{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0}};

inline void eval ()
{
    int a = num.top(); num.pop();
    int b = num.top(); num.pop();

    char oper = op.top(); op.pop();
    
    int res = 0;
    if (oper == '+') res = b + a; 
    if (oper == '-') res = b - a; 
    if (oper == '*') res = b * a; 
    if (oper == '/') res = b / a; 

    num.push (res);
}

int main ()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            int x = 0;
            while (i < s.size() and isdigit(s[i]))
            {
                x = x * 10 + s[i] - '0';
                i ++;
            }
            i --;
            num.push (x);
        }
        else if (s[i] == '(')
        {
            op.push (s[i]);
        }
        else if (s[i] == ')')
        {
            while (op.top() != '(')
            {
                eval ();
            }
            op.pop();
        }
        else
        {
            while (not op.empty() and h[op.top()] >= h[s[i]])
            {
                eval ();
            }
            op.push(s[i]);
        }
    }

    while (not op.empty ())
    {
        eval ();
    }
    cout << num.top () << endl;

    return 0;
}