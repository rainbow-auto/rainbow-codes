#include <iostream>
#include <string>

const int maxn = 105;

int n;
std::string a[maxn];

int main () {

    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    for (int i = 2; i <= n; i++) { 
        if (a[i] == "sweet" and a[i - 1] == "sweet") { 
            if (i == n) { continue; }
            std::cout << "No\n"; return 0; 
        }
    }
    std::cout << "Yes\n";

    return 0;
}