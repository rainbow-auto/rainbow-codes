#include <iostream>
using namespace std;

inline int read ()
{
    int res = 0, flag = 1;
    char ch = getchar ();
    while (not isdigit(ch))
    {
        if (ch == '-')
        {
            flag = -1;
        }
        ch = getchar();
    }
    while (isdigit(ch))
    {
        res = res * 10 + (ch - '0');
        ch = getchar();
    }
    return res * flag;
}

const int maxn = 105;
int n;
int a[maxn];

int main ()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    
    int ans = 0;
    for (int i = 1; i + 3 - 1 <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += a[i + j];
        }
        ans = max (ans, sum);
    }
    cout << ans << endl;

    return 0;

}