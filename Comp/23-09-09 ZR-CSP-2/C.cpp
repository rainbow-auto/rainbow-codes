#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 100005;

namespace Solution {
    struct Node {
        int nxt, pre;
    } a[26];

    int ans[maxn];    

    int fa[26];
    int find (int x) { if (x != fa[x]) { return fa[x] = find (fa[x]); } else { return fa[x]; } }

    inline void connect (int x, int y) { a[x].nxt = y; a[y].pre = x; fa[x] = find (fa[y]); }

    inline void solve (string s) {
        for (int i = 0; i < 26; i++) { a[i].nxt = -1; a[i].pre = -1; fa[i] = i; }

        for (int i = 0; i < s.size (); i++) {
            // for (int j = 0; j < 26; j++) { cout << char (j + 'a') << " pre : " << a[j].pre << " nxt : " << a[j].nxt << endl; }
            
            int now = s[i] - 'a';

            if (a[now].pre != -1) { ans[i] = a[now].pre; continue; }

            int t = -1;
            for (int j = 0; j < 26; j++) {
                if (find (now) == find (j)) { continue; }

                if (a[j].nxt == -1) { connect (j, now); t = j; break; }
            }

            ans[i] = t;
        }


        for (int i = 0; i < s.size (); i++) { cout << char (ans[i] + 'a'); } cout << endl;
    }  
  
}

int T;

int main () {

    cin >> T;

    while (T--) {
        int tmp; cin >> tmp;
        string s; cin >> s;

        Solution::solve (s);
    }

    return 0;
}