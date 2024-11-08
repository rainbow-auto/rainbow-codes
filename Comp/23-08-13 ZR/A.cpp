#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {

    vector<int> a({1, 2, 3, 4, 5}); 
    vector<int> b({12, 4, 8, 9, 11});

    do {
        int hh = 0; for (int i = 0; i < 3; i++) { hh += b[a[i]]; }
        int hp = 0; for (int i = 3; i < 5; i++) { hp += b[a[i]]; }
        
        if (hh - hp == -3) { cout << "find  it!" << endl; return 0; }

    } while (next_permutation(a.begin(), a.end()));

    return 0;
}