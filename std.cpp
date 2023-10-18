#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>

#define int long long
const int MN=3005;

using namespace std;

inline int read(){
    int x=0,f=1;char c=getchar();
    for(;(c<'0'||c>'9');c=getchar()){if(c=='-')f=-1;}
    for(;(c>='0'&&c<='9');c=getchar())x=x*10+(c&15);
    return x*f;
}

char s[MN],t[MN];
int dp[MN][MN],pi[MN][MN],n,m;
char ans[MN];

int cnt=0;
void print(int x,int y){
    if(x==0||y==0)return ;
    if(pi[x][y]==1)ans[cnt++]=s[x],print(x-1,y-1);
    else if(pi[x][y]==2)print(x-1,y);
    else print(x,y-1);
}

signed main(void){

    cin>>(s+1)>>(t+1);
    n=strlen(s+1),m=strlen(t+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i]==t[j])dp[i][j]=dp[i-1][j-1]+1,pi[i][j]=1;
            else if(dp[i-1][j]>dp[i][j-1])dp[i][j]=dp[i-1][j],pi[i][j]=2;
            else dp[i][j]=dp[i][j-1],pi[i][j]=3;
        }
    }
    print(n,m);
    reverse(ans,ans+cnt);
    cout<<ans<<endl;

    return 0;
}
