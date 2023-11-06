#include <iostream>
using namespace std;

typedef unsigned long long ll;

int solve (ll num)
{
    num /= 10;
    return num % 10;
}

int main ()
{
    cin >> num;
    cout << solve (num) << endl;
    return 0;
}