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

const int maxn = 55;

int sum;
int n;
int a[maxn];
int x;

int main ()
{
    n = read();

    for (int i = 1; i <= n; i++)
    {
        a[i] = read ();
        sum += a[i];
    }

    x = sum / n;

    int ans = 0;
    int now = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < x)
        {
            if (now >= a[i] - x)
            {
                ans += a[i] - x;
                now -= a[i] - x;
            }
            else
            {
                
            }
        }
        
    }

    return 0;
}