#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
    string s;
    cin >> s;
    reverse (s.begin(), s.end());
    cout << s[1] << endl;
    return 0;
}
