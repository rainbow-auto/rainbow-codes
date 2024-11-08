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

#include <unordered_map>

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

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

string start;

int bfs ()
{
    unordered_map <string, int> dis;
    queue<string> q;
    
    string end = "12345678x";
    q.push (start);
    dis[start] = 0;

    while (not q.empty ())
    {
        string t = q.front(); q.pop();
        int d = dis[t];
        if (t == end) return d;

        int index = t.find("x");
        int x = index / 3;
        int y = index % 3;

        for (int i = 0; i < 4; i++)
        {
            int px = x + dx[i];
            int py = y + dy[i];
            if (px < 0 or px >= 3) continue;
            if (py < 0 or py >= 3) continue;

            swap (t[px * 3 + py], t[x * 3 + y]);
            if (not dis.count (t))
            {
                dis[t] = d + 1;
                q.push(t);   
            }

            swap (t[px * 3 + py], t[x * 3 + y]);
        }
    }
    return -1;
}

int main ()
{
    for (int i = 1; i <= 9; i++)
    {
        char curr;
        cin >> curr;
        start += curr;
    }

    cout << bfs () << endl;
    return 0;
}