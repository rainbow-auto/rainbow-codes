// ����
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

const int maxn = 2000005;
const int mod = 1e9 + 7;

int cnt;
int to[maxn], pre[maxn], last[maxn];
inline void addEdge (int u, int v)
{
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;    
}

int n, m;

namespace Reader{
    inline int read ()
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
    
    inline int work ()
    {
        n = read (); m = read ();
        bool t1_flag = (m == n - 1); // 链
        bool t2_flag = (m == n - 1); // 树
        for (int i = 1; i <= n; i++)
        {
            int u = read (), v = read ();
            addEdge (u, v);
            addEdge (v, u);
            if (not (u == v + 1 or v == u + 1))
            {
                t1_flag = false;
            }
        }
        if (t1_flag)
        {
            return 1;
        }
        else if (t2_flag)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
}

namespace Utility{
    inline int ksm (int a, int b)
    {
        int ans = 1;
        for (int base = a; b; base *= base, base %= mod, b >>= 1) 
        {
            if (b & 1)
            {
                ans *= base;
                ans %= mod;
            }
        }
        return ans;
    }
}

namespace Sub1{
    inline void solve ()
    {
         
    }
}

int main ()
{
    int Task = Reader::work ();
    if (Task == 1)
    {
        
    }
    else if (Task == 2)
    {

    }
    else if (Task == 3)
    {
        
    }

    return 0;
}
