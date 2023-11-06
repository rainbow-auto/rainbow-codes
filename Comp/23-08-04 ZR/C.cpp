#include <iostream>
using namespace std;

int n;

int main () {

    cin >> n;

    if (n == 1) {
        cout << "000" << endl;
        cout << "000" << endl;
        cout << "000" << endl;
    }
    if (n == 2) {
        cout << "000" << endl;
        cout << "000" << endl;
        cout << "000" << endl;
    }
    if (n == 3) {
        cout << "010" << endl;
        cout << "001" << endl;
        cout << "100" << endl;
    }
    if (n == 4) {
        cout << "010" << endl;
        cout << "001" << endl;
        cout << "100" << endl;
    }

    return 0;
}