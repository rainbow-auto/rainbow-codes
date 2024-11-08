#include <iostream>
#include <random>
#include <ctime>
#include <windows.h>
#include <algorithm>

using namespace std;

void gen () {
    freopen ("in", "w", stdout);

    int k = rand() % 10000;
    int rd1 = rand() % 10000, rd2 = rand() % 10000;
    cout << k << " " << min(rd1, rd2) << " " << max(rd1, rd2) << endl;
    
    fclose (stdout);
}

int main () {
    int n = 100005;

    srand(time(0));

    for (int i = 1; i <= n; i++) {
        gen();
        if (system("scode.exe < in")) {
            cout << "WA on #" << i << endl;
            return 114514;
        }
    }    

    return 0;
}
