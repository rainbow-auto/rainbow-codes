#include <iostream>

using namespace std;

const int maxn = 10005;

int n;
string s;

queue<int> q;

int main () {

    cin >> n;
    cin >> s;

    for (int i = 0; i < s.size ();  i++) {
        if (s[i] == '(') { q.push (i); }
    }
    
    int lcnt = 0;
    int rcnt = 0;
    for (int i = 0; i < s.size ();  i++) {
        lcnt += s[i] == '(';
        rcnt += s[i] == ')';
        if (lcnt >= rcnt) { continue; }

        while (i >= q.front()) { q.pop (); }

        int j = q.front (); q.pop ();

        
    }

    return 0;
}