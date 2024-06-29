#include <iostream>

const int maxn = 100005;

bool vis[maxn];

int main () {

    int n; std::cin >> n;

    int cnt = 0;

    int first; std::cin >> first;
    if (first == -1) { return 0; }
    
    cnt ++; vis[first] = true;

    for (int i = 2; i <= n; i++) {
        int x; std::cin >> x;

        if (x == -1 and i != 1) { std::cout << "i = " << i << " Invalid Input\n"; return -1; }

        if (not vis[x]) { cnt ++; vis[x] = true; }

        if (not (i & 1) and (cnt & 1)) { std::cout << "Wrong Answer!\n"; return -1; }
    }

    std::cout << "Accepted\n";

    return 0;
}