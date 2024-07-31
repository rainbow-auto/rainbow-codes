#include <iostream>
#include <vector>
#include <algorithm>

int main () {

    std::vector <int> a;
    a.push_back (1); a.push_back (3); a.push_back (7);

    int ans = std::lower_bound (a.begin (), a.end (), 1) - a.begin ();

    std::cerr << ans << "\n";

    return 0;
}