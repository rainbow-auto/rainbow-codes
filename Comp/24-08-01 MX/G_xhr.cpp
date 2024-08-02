#include<bits/stdc++.h>
using namespace std;
long long n,q,block,num;
long long a[1000010],belong[1000010],s[1000010],tag[1000010],L[1000010],R[1000010];
void edit(long long l,long long r,long long k)
{
    if(belong[l] == belong[r])
    {
        long long now = belong[l];
        for(long long i = l;i <= r;i++)
        {
            a[i] += k;
        }
        for(long long i = L[now];i <= R[now];i++)
        {
            s[i] = a[i];
        }
        sort(s + L[now],s + R[now] + 1);
        return;
    }
    long long now = belong[l];
    for(long long i = l;i <= R[now];i++)
    {
        a[i] += k;
    }
    for(long long i = L[now];i <= R[now];i++)
    {
        s[i] = a[i];
    }
    sort(s + L[now],s + R[now] + 1);
    now = belong[r];
    for(long long i = L[now];i <= r;i++)
    {
        a[i] += k;
    }
    for(long long i = L[now];i <= R[now];i++)
    {
        s[i] = a[i];
    }
    sort(s + L[now],s + R[now] + 1);
    for(long long i = belong[l] + 1;i <= belong[r] - 1;i++)
    {
        tag[i] += k;
    }
}
long long query(long long l,long long r,long long k)
{
    long long ans = 0;
    if(belong[l]== belong[r])
    {
        long long now = belong[l];
        for(long long i = l;i <= r;i++)
        {
            ans += (tag[now] + a[i] >= k);
        }
        return ans;
    }
    long long now = belong[l];
    for(long long i = l;i <= R[now];i++)
    {
        ans += (tag[now] + a[i] >= k);
    }
    now = belong[r];
    for(long long i = L[now];i <= r;i++)
    {
        ans += (tag[now] = a[i] >= k);
    }
    for(long long i = belong[l] + 1;i <= belong[r] - 1;i++)
    {
        long long id = lower_bound(s + L[i],s + R[i] + 1,k - tag[i]) - s;
        ans += R[i] - id + 1;
    }
    return ans;
}
int main()
{
    cin >> n >> q;
    block = (long long)sqrt(n);
    num = n / block + (n % block != 0);
//    cout << block << " " << num << endl;
    for(long long i = 1;i <= n;i++)
    {
        cin >> a[i];
        belong[i] = (i - 1) / block + 1;
    }
    for(long long i = 1;i <= num;i++)
    {
        L[i] = (i - 1) * block + 1;
        R[i] = i * block;
        if(i == num)
        {
            R[i] = n;
        }
        for(long long j = L[i];j <= R[i];j++)
        {
            s[j] = a[j];
        }
//        cout << L[i] << " " << R[i] << endl;
        sort(s + L[i],s + R[i] + 1);
    }
    for(long long i = 1;i <= q;i++)
    {
        char ch;
        long long l,r,k;
        cin >> ch >> l >> r >> k;
        if(ch == 'M')
        {
            edit(l,r,k);
//            for(long long i = 1;i <= n;i++)
//            {
//                cout << s[i] << " " << endl;
//            }
        }
        else{
            cout << query(l,r,k) << endl;
        }
    }
    return 0;
}