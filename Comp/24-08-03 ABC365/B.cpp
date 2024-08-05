#include <iostream>
#include <algorithm>

const int maxn = 100005;

int n;
struct Node {
    int val, id;

    friend bool operator < (Node a, Node b) {
        return a.val > b.val;
    }
} a[maxn];

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) { int x; std::cin >> x; a[i] = Node { x, i }; }

    std::sort (a + 1, a + n + 1);

    std::cout << a[2].id << "\n";

    return 0;
}