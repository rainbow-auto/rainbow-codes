#include<bits/stdc++.h>
using namespace std;
struct node
{
	int v,w,next,other;
}edge[100010];

int from[100010],h[100010],q[100010];
int n,m,num,f,d,st,ed;

void addedge(int x,int y,int c)
{
	int k1,k2;
	num++;
	k1=num;
	edge[num].v=y;
	edge[num].w=c;
	edge[num].next=from[x];
	from[x]=num;
	
	num++;
	k2=num;
	edge[num].v=x;
	edge[num].w=0;
	edge[num].next=from[y];
	from[y]=num;
	
	edge[k1].other=k2;
	edge[k2].other=k1;
}

int head,tail; 

bool bfs()
{
	memset(h,0,sizeof(h));
	h[st]=1;
	q[1]=st;
	head=1;tail=2;
	while(head!=tail)
	{
		int x=q[head];
		for(int k=from[x];k;k=edge[k].next)
		{
			int y=edge[k].v;
			if((edge[k].w>0)&&(h[y]==0))
			{
				h[y]=h[x]+1;
				q[tail]=y;
				tail++;
			}
		}
		head++;
	}
	if(h[ed]>0) return true;else return false;
}

int dfs(int x,int f)
{
	if(x==ed) return f;
	int s=0,t;
	for (int k=from[x];k;k=edge[k].next)
	{
		int y=edge[k].v;
		if((h[y]==(h[x]+1))&&(edge[k].w>0)&&(s<f))
		{
			t=dfs(y,min(f-s,edge[k].w));
			s+=t;
			edge[k].w-=t;
			edge[edge[k].other].w+=t;
		}
	}
	if (s==0) h[x]=0;
	return s;
}

int main()
{
	cin>>n>>f>>d;
	st=0;
	ed=n*2+f+d+1;
	for(int i=1;i<=f;i++) addedge(st,i,1);
	for(int i=1;i<=n;i++) addedge(i+f,i+f+n,1);
	for(int i=1;i<=d;i++) addedge(i+2*n+f,ed,1);
	for(int i=1;i<=n;i++)
	{
		int f1,d1;
		cin>>f1>>d1;
		for(int j=1;j<=f1;j++)
		{
			int x;
			cin>>x;
			addedge(x,i+f,1);
		}
		for(int j=1;j<=d1;j++)
		{
			int x;
			cin>>x;
			addedge(n+i+f,n+n+f+x,1);
		}
	}
	
	int ans = 0;
	while(bfs())
	{
		cout << "dis_before: ";
		for (int i = 0; i <= ed; i++)
		{
			cout << h[i] << " ";
		}
		cout << endl;
		
		ans+=dfs(st,19270817);
		
		cout << "dis_after: ";
		
		for (int i = 0; i <= ed; i++)
		{
			cout << h[i] << " ";
		}
		cout << endl;
		
	}
	
	
	cout<<ans;
	return 0;
}
