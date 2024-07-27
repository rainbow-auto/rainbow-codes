#include <iostream>
#include <algorithm>

using i64 = long long;

const int maxn = 200005;

int n;
struct Node {
    i64 a, b;
} a[maxn];

i64 x, y;

inline bool sort_by_a (Node a, Node b) {
    return a.a > b.a;
}

inline bool sort_by_b (Node a, Node b) {
    return a.b > b.b;
}

int main () {

    std::cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) { std::cin >> a[i].a; }
    for (int i = 1; i <= n; i++) { std::cin >> a[i].b; }

    std::sort (a + 1, a + n + 1, sort_by_a);

    i64 a_sum = 0;
    int cnt_a = 0;
    for (int i = 1; i <= n; i++) {
        a_sum += a[i].a;
        if (a_sum > x) { cnt_a = i; goto IE1; }
    }

    cnt_a = n;

    IE1:;

    std::sort (a + 1, a + n + 1, sort_by_b);

    i64 b_sum = 0;
    int cnt_b = 0;
    for (int i = 1; i <= n; i++) {
        b_sum += a[i].b;
        if (b_sum > y) { cnt_b = i; goto IE2; }
    }

    cnt_b = n;

    IE2:;

    std::cout << std::min (cnt_a, cnt_b) << "\n";

    return 0;
}