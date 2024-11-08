#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

namespace Reader{
    int read ()
    {
        char c = getchar (); 
        int x = 0, flag = 1;
        while (not isdigit (c)) { if (c == '-') flag = -1; c = getchar(); }
        while (isdigit (c)) { x = x * 10 + c - '0'; c = getchar(); }
        return x * flag;
    }
}

const int maxn = 1000010;
int n;

int h[maxn];
int ph[maxn]; // 第k个插入到点的位置
int hp[maxn]; // 第i个点是第几个插入的
int siz;

inline void heap_swap (int a, int b)
{
    swap (h[a], h[b]);
    swap (hp[a], hp[b]);
    swap (ph[hp[a]], ph[hp[b]]);
}

void up (int x)
{
    if (x / 2 > 0 and h[x] < h[x / 2])
    {
        heap_swap (x, x / 2);
        up (x / 2);
    }
}

void down (int x)
{
    int t = x;
    if (x * 2 <= siz and h[t] > h[x * 2]) t = x * 2;
    
    if (x * 2 + 1 <= siz and h[t] > h[x * 2 + 1]) t = x * 2 + 1;

    if (t != x)
    {
        heap_swap (x, t);
        down (t);
    }
}

int main ()
{
    n = Reader::read();

    int curr = 0;
    for (int i = 1; i <= n; i++)
    {
        string op;
        cin >> op;
        if (op == "I")
        {
            int x = Reader::read();
            curr ++;
            h[++siz] = x;
            ph[curr] = siz; 
            hp[siz] = curr;
            up (siz);
            // display ();
        }
        else if (op == "PM")
        {
            cout << h[1] << endl;
        }
        else if (op == "DM")
        {
            heap_swap (1, siz);
            siz --;
            down (1);
            // display ();
        }
        else if (op == "D")
        {
            int k = Reader::read();
            int phk = ph[k];
            heap_swap (phk, siz);
            siz --;
            up (phk);
            down (phk);
            // display ();
        }
        else if (op == "C")
        {
            int k = Reader::read();
            int x = Reader::read();
            int phk = ph[k];
            h[phk] = x;
            down (phk);
            up (phk);
            // display ();
        }
    }
    return 0;
}