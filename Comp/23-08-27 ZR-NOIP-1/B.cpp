#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <string>

using namespace std;

const int maxn = 105;

map<char, int> dx;
map<char, int> dy;

int n;
string s;

struct Node {
    int x, y;

    friend bool operator < (Node a, Node b) {
        if (a.x != b.x) { return a.x < b.x; }
        else { return a.y < b.y; }
    }
};

set<Node> ans;

inline Node getPos (Node now) { return Node { now.x + 20, now.y + 20 }; }
inline Node getRealPos (Node now) { return Node { now.x - 20, now.y - 20 }; }
inline Node getNext (Node now, char op) { return Node { now.x + dx[op], now.y + dy[op] }; }

int mark[maxn][maxn];
void check (Node now, int S, int cur) {
    if (mark[now.x][now.y]) { return; }
    if (cur == n) { return; }

    if (S & (1 << cur)) {
        check (getNext(now, s[cur]), S, cur + 1);
    } else {
        mark[getNext (now, s[cur]).x][getNext (now, s[cur]).y] = true;
        check (now, S, cur + 1);
    }
}

void dfs (Node now, int S, int cur) {
    if (mark[now.x][now.y]) { return; }
    if (cur == n) { now = getRealPos(now); ans.insert (now); return; }

    if (S & (1 << cur)) {
        dfs (getNext(now, s[cur]), S, cur + 1);
    } else {
        dfs (now, S, cur + 1);
    }
}

signed main () {
    
    // init dx & dy
    dx['L'] = -1; dy['L'] = 0;
    dx['R'] = 1; dy['R'] = 0;
    dx['D'] = 0; dy['D'] = -1;
    dx['U'] = 0; dy['U'] = 1;

    cin >> n;
    cin >> s;

    int tot = (1 << n) - 1;
    for (int S = 0; S <= tot; S++) {
        memset (mark, 0, sizeof (mark));
        
        check (getPos (Node { 0, 0 }), S, 0);
        dfs (getPos (Node { 0, 0 }), S, 0);
    }

    cout << ans.size () << endl;
    for (auto now : ans) {
        cout << now.x << " " << now.y << endl;
    }

    return 0;
}