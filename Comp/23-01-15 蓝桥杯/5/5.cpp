#include <iostream>

using namespace std;

const int maxn = 55;

int n;
double a[maxn];
int dp_1[maxn];
int dp_2[maxn];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
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
        ans = max (ans, dp_1[i] + dp_2[i] - 1);
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