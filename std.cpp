#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int n,m;
string s[102];

void p0(){
	sort(s[1].begin(),s[1].end());
	sort(s[2].begin(),s[2].end());
	reverse(s[2].begin(),s[2].end());
	if(s[1]<s[2])puts("Yes");
	else puts("No");
}

void p1(){
	bool flg=1;
	for(int i=1;i<=n;i++){
		sort(s[i].begin(),s[i].end());
	}
	for(int i=2;i<=n;i++){
		vector<string>cur;
		for(int j=0;j<m;j++){
			string t=s[i];
			bool ab=1;
			for(int k=0;k<j;k++){
				if(t[k]!=s[i-1][k]){
					int pt=k;
					while(pt<m&&t[pt]!=s[i-1][k])pt++;
					if(pt<m&&t[pt]==s[i-1][k])swap(t[pt],t[k]);
					else{
						ab=0;break;
					}
				}
			}
			if(!ab)continue;
			sort(t.begin()+j,t.end());
			if(t[j]<=s[i-1][j]){
				int pt=j;
				while(pt<m&&t[pt]<=s[i-1][j])pt++;
				if(pt<m&&t[pt]>s[i-1][j]){
					swap(t[pt],t[j]);
				}else{
					continue;
				}
			}
			sort(t.begin()+j+1,t.end());
			cur.push_back(t);
		}
		sort(cur.begin(),cur.end());
		if(!cur.empty())s[i]=cur[0];
		else{
			flg=0;
			break;
		}
	}
	
	if(flg)puts("Yes");
	else puts("No");
}

void solve(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n==1)puts("Yes");
	else if(n==2)p0(); 
	else p1();
}

int main(){
	int t=read();
	while(t--)solve();
	return 0;
} 