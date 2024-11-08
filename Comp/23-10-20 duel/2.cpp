#include <iostream>
#include <map>
#include <vector>

using i64 = long long;

const int maxn = 200005;

int n;

int a[maxn], b[maxn], c[maxn];
std::map<int, std::vector<int> > m;

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
    for (int i = 1; i <= n; i++) { std::cin >> b[i]; }

    for (int i = 1; i <= n; i++) { c[i] = a[i] - b[i]; }

    for (int i = 1; i <= n; i++) {
        int x = c[i];
        
    }      

    return 0;
}