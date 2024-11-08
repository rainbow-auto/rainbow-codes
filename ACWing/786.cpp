#include <iostream>
using namespace std;

const int maxn = 1000005;

int n, k;
int a[maxn];

void QuickSort (int l, int r)
{
    if (l >= r)
    {
        return;
    }
    
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
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    QuickSort (1, n);
    
    cout << a[k] << endl;

    return 0;
}