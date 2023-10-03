#include <algorithm>
#include <iostream>
#include <cstdio>

#define FILE_IN(__fname) freopen(__fname, "r", stdin)
#define FILE_OUT(__fname) freopen(__fname, "w", stdout)
#define IMPROVE_IO() std::ios::sync_with_stdio(false)

#define WHITE 0
#define BLACK 1

using std::cin;
using std::cout;
using std::endl;
using std::max;

const int MAXV = 50000 + 10;
const int MAXE = 100000 + 10;
const int MAXW = 100;

struct Edge {
    int prev, next, weight, add;
    bool color;
    // 1 -> black, 0 -> white
    
    Edge() { prev = next = weight = color = add = 0; }
    
    bool operator < (const Edge &that) const {
        if (weight == that.weight) return color < that.color;
        return weight < that.weight;
    }
} edge[MAXE << 1];

int V, E, Need, cnt, ans;

int U[MAXV << 1];

int Find(int x) {
    if (U[x] == x) return U[x];
    return U[x] = Find(U[x]);
}

bool Union(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return false;
    U[x] = y;
    return true;
}

int Kruskal() {
    int whiteEdge = 0;
    for (int i = 1; i <= V; ++i) U[i] = i;
    std::sort(edge + 1, edge + 1 + E);
    int tot = 0;
    ans = 0;
    for (int i = 1; i <= E; ++i) {
        if (Union(edge[i].prev, edge[i].next)) 
            ans += edge[i].weight, ++tot, whiteEdge += (edge[i].color == WHITE);
        if (tot == V - 1) break;
    }
    return whiteEdge;
}

bool Check(int add) {
    for (int i = 1; i <= E; ++i) {
        if (edge[i].color == WHITE) edge[i].weight += add;
    }
    bool Ans = (Kruskal() >= Need);
    for (int i = 1; i <= E; ++i) {
        if (edge[i].color == WHITE) edge[i].weight -= add;
    }
    return Ans;
}

int main() {
    IMPROVE_IO();
    cin >> V >> E >> Need;
    for (int i = 1; i <= E; ++i) {
    	cin >> edge[i].prev >> edge[i].next >> edge[i].weight >> edge[i].color;
    	++edge[i].prev;
        ++edge[i].next;
    }
    int l = -MAXW, r = MAXW;
    int Run = 0;
    while (l <= r) {
        int mid = ((l + r) >> 1);
        cout << "add " << mid << " ";
        if (Check(mid)) {
            cout << "ok" << endl;
            l = mid + 1;
            Run = mid;
        } else {
            cout << endl;
            r = mid - 1;
        }

        cout << "mst: " << ans << endl;
    }
    Check(Run);

    cout << "mst: " << ans << endl;
    cout << "res: " << Run << endl;
    cout << "need: " << Need << endl;

    cout << ans - Need * Run << endl;
    return 0;
}

/*
add 0 ok mst = 192
add 50 
add 25 
add 12 ok mst = 273
add 18 ok mst = 301
add 21 ok mst = 310
add 23 
add 22 
mst: 310
res: 21
need: 3
247
*/