#include <iostream>

using namespace std;

int A, B;

inline bool check (int a, int b, int c) {
    int red = 0, black = 0;
    
    if (a == 1 or a == 4) { red += a; }
    else { black += a; }

    if (b == 1 or b == 4) { red += b; }
    else { black += b; }

    if (c == 1 or c == 4) { red += c; }
    else { black += c; }

    return red == A and black == B;
}

int main () {

    cin >> A >> B;

    for (int a = 1; a <= 6; a ++) 
    for (int b = 1; b <= 6; b ++) 
    for (int c = 1; c <= 6; c ++)
    if (check (a, b, c)) { cout << "Yes" << endl; return 0; }

    cout << "No" << endl;

    return 0;
}