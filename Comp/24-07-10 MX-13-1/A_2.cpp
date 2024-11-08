#include <iostream>
#include <cmath>

using f64 = double;

int main () {

    // freopen ("Apair.in", "r", stdin);
    // freopen ("Apair.out", "w", stdout);

    f64 ans = sqrt (2.0);    

    int T; std::cin >> T;

    while (T--) { printf ("%.12lf\n", ans); }

    return 0;
}