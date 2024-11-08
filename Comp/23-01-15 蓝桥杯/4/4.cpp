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

const int maxn = 35;
int n, m;

char g[maxn][maxn];

int a[maxn][maxn];
int b[maxn][maxn];
int c[maxn][maxn];

int s_a[maxn][maxn];
int s_b[maxn][maxn];
int s_c[maxn][maxn];

int get_sum_a (int x1, int y1, int x2, int y2)
{
    return s_a[x2][y2] - s_a[x1 - 1][y2] - s_a[x2][y1 - 1] + s_a[x1 - 1][y1 - 1];
}
int get_sum_b (int x1, int y1, int x2, int y2)
{
    return s_b[x2][y2] - s_b[x1 - 1][y2] - s_b[x2][y1 - 1] + s_b[x1 - 1][y1 - 1];
}
int get_sum_c (int x1, int y1, int x2, int y2)
{
    return s_c[x2][y2] - s_c[x1 - 1][y2] - s_c[x2][y1 - 1] + s_c[x1 - 1][y1 - 1];
}

int main ()
{
    n = read();
    m = read();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'a')
            {
                a[i][j] = 1;
            }
            else if (g[i][j] == 'b')
            {
                b[i][j] = 1;
            }
            else if (g[i][j] == 'c')
            {
                c[i][j] = 1;
            }

            s_a[i][j] = s_a[i - 1][j] + s_a[i][j - 1] - s_a[i - 1][j - 1] + a[i][j];
            s_b[i][j] = s_b[i - 1][j] + s_b[i][j - 1] - s_b[i - 1][j - 1] + b[i][j];
            s_c[i][j] = s_c[i - 1][j] + s_c[i][j - 1] - s_c[i - 1][j - 1] + c[i][j];
        }
    }

    int ans = 0;
    for (int x1 = 1; x1 <= n; x1 ++)
    {
        for (int y1 = 1; y1 <= m; y1 ++)
        {
            for (int len = 2; x1 + len - 1 <= n and y1 + len - 1 <= m; len ++)
            {
                int x2 = x1 + len - 1;
                int y2 = y1 + len - 1;

                if (get_sum_a (x1, y1, x2, y2) == len * len)
                {
                    ans ++;    
                }
                else if (get_sum_b (x1, y1, x2, y2) == len * len)
                {
                    ans ++;
                }
                else if (get_sum_c (x1, y1, x2, y2) == len * len)
                {
                    ans ++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}