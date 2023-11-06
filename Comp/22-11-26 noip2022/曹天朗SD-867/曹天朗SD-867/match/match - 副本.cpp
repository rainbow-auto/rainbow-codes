// ±©Á¦
// 20pts ? 

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

int read ()
{
	int res = 0, flag = 1;
	char ch = getchar ();
	while (not isdigit (ch))
	{
		if (ch == '-') flag = -1;
		ch = getchar ();
	}
	while (isdigit (ch))
	{
		res = res * 10 + int (ch - '0');
		ch = getchar ();
	}
	return res * flag;
}

const int maxn = 250005;
int n, T;
int a[maxn], b[maxn];
int Q;
int ql[maxn], qr[maxn];

typedef unsigned long long ll;

namespace Reader{
    inline void work()
    {
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
        }
        for (int i = 1; i <= n; i++)
        {
            b[i] = read();
        }
        Q = read();
        for (int i = 1; i <= Q; i++)
        {
            ql[i] = read();
            qr[i] = read();
        }  
    }
}

namespace Baoli{
    inline void solve ()
    {
        Reader::work();
        for (int qnow = 1; qnow <= Q; qnow ++)
        {
            int L = ql[qnow];
            int R = qr[qnow];
            ll ans = 0;
            for (int p = L; p <= R; p++)
            {
                int ma = a[p];
                int mb = b[p];
                for (int q = p; q <= R; q++)
                {
                    ma = max (ma, a[q]);
                    mb = max (mb, b[q]);
                    ans += ma * mb;
                }
            }
            cout << ans << endl;
        }
    }
}

int main ()
{
	//freopen ("match.in", "r", stdin); 
	//freopen ("match.out", "w", stdout); 

    T = read(), n = read();
    
    Baoli::solve ();

    //fclose (stdin);
    //fclose (stdout);
	return 0;
}
