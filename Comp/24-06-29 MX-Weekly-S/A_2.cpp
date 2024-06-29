#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

const int maxn = 25;

int n;
int a[maxn];

std::vector <int> ord;

bool vis[maxn];

bool check () {
    memset (vis, 0, sizeof (vis));
    
    int cnt = 0;

    int i = 1;
    for (auto now : ord) {
        if (not vis[a[now]]) {
            cnt ++;
            vis[a[now]] = true;
        }       
        
        if ((cnt & 1) and not (i & 1)) { return false; }

        i++;
    }

    return true;
}

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        ord.push_back (i);
    }

    // std::cout << n << "\n";

    do {
        if (check ()) {
            for (auto now : ord) { std::cout << a[now] << " "; } std::cout << "\n";
            goto End;
        }
    } while (std::next_permutation (ord.begin (), ord.end ()));

    std::cout << -1 << "\n";

    End: ;

    return 0;
}