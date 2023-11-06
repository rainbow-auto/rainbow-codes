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

int n;
double a[maxn];
int dp_1[maxn];
int dp_2[maxn];

int main ()
{
    n = read();

    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }

    for (int i = 1; i <= n; i++)
    {
        dp_1[i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            if (a[i] > a[j])
            {
                dp_1[i] = max (dp_1[i], dp_1[j] + 1);
            }
        }
    }

    for (int i = n; i >= 1; i--)
    {
        dp_2[i] = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] > a[j])
            {
                dp_2[i] = max (dp_2[i], dp_2[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max (ans, dp_1[i] + dp_2[i]);
    }
    if (n - ans == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << n - ans << endl;
    }
    
    return 0;
}