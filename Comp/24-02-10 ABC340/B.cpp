#include <iostream>
#include <vector>

int Q;

std::vector<int> a;

int main () {

    std::cin >> Q;

    while (Q--) {
        int op, x; std::cin >> op >> x;
        if (op == 1) {
            a.push_back (x);
        } else {
            std::cout << a[a.size () - x] << "\n";
        }
    }

    return 0;
}