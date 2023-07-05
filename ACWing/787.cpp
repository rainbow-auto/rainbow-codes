/*
    本题应该使用归并排序
    可我不会归并排序
    因此使用手写快排通过 （用sort似乎有点不道德233
*/

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

const int maxn = 100005;

int n;
int a[maxn];

void QuickSort (int l, int r)
{
    if (l >= r) return;
    int x = a[l + r >> 1];
    int i = l - 1;
    int j = r + 1;
    while (i < j)
    {
        do i ++; while (a[i] < x);
        do j --; while (a[j] > x);
        if (i < j) swap (a[i], a[j]);
    }
    QuickSort (l, j);
    QuickSort (j + 1, r);
}

int main ()
{
    n = Reader::read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = Reader::read();
    }   

    QuickSort (1, n);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    
    return 0;
}