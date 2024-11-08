#include <iostream>

using namespace std;

const int maxn = 1005;

struct Edge {
    int u, v;
    int a, b;

    int pre;
} es[maxm];

int last[maxn], cnt;

inline void addEdge (int u, int v, int _a, int _b) {
    es[++cnt] = Edge { u, v,  _a, _b, last[u] };
    last[u] = cnt;
}
6
int main () {

    return 0;
}