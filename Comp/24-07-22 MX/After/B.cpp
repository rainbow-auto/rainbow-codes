#include <iostream>
#include <queue>    
#include <map>
#include <algorithm>

using i64 = long long;

const int maxn = 100005;

int n;

struct Node {
    int pos;
    i64 w;

    friend bool operator < (Node a, Node b) {
        return a.pos < b.pos;
    }
} ns[maxn];

int main () {

    freopen ("resource.in", "r", stdin);
    freopen ("resource.out", "w", stdout);

    std::cin >> n;
    
    for (int i = 1; i <= n; i++) { std::cin >> ns[i].pos; }
    for (int i = 1; i <= n; i++) { std::cin >> ns[i].w; }
    ns[n + 1].pos = 2e9;

    std::sort (ns + 1, ns + n + 1);

    std::priority_queue <i64> q;
    i64 sum = 0;

    i64 ans = 0;

    q.push (ns[1].w); sum += ns[1].w;

    for (int i = 2; i <= n + 1; i++) {
        if (ns[i].pos != ns[i - 1].pos) {
            sum -= q.top (); q.pop ();

            int curr = 1;
            while (not q.empty ()) { 
                if (ns[i - 1].pos + curr >= ns[i].pos) {
                    ans += sum * curr;
                    break; 
                }

                ans += curr * q.top (); sum -= q.top (); q.pop (); 
                curr ++; 
            }
        }
        q.push (ns[i].w); sum += ns[i].w;
    }

    std::cout << ans << "\n";

    return 0;
}