#include <iostream>
#include <cstdlib>

using namespace std;

int main () {

    freopen ("take.in", "r", stdin);
    freopen ("take.out", "w", stdout);

    srand (time (0));
    cout << rand () % 10 + 1 << endl;

    return 0;
}