#include<bits/stdc++.h>
using namespace std;
int n,m,vis[510][510][3],ans=-1;
char a[510][510];
struct node{
	//坐标，状态，步数
    int x,y,zt,bs;
    /*
    zt=0 X

    zt=1 XX

    zt=2 X
         X
    */
}st,ed;//起点，终点
void bfs(){
	queue<node> q;
    q.push(st);
    while(!q.empty()){
        int x=q.front().x,y=q.front().y,zt=q.front().zt,bs=q.front().bs;
        //cout<<x<<" "<<y<<" "<<zt<<"\n";
        q.pop();
        if(x==ed.x&&y==ed.y&&zt==ed.zt){//到终点了
			ans=bs;
		    return;
		}
        if(a[x][y]=='E'&&!zt) continue;//直立在E格上
        if(a[x][y]=='#'||(a[x][y+1]=='#'&&zt==1)||(a[x+1][y]=='#'&&zt==2)) continue;//越界
        if(vis[x][y][zt]) continue;//同一状态下走过了
        vis[x][y][zt]=1;//标记走过了
        if(!zt){//直立时
            q.push({x,y-2,1,bs+1});
            q.push({x,y+1,1,bs+1});
            q.push({x-2,y,2,bs+1});
            q.push({x+1,y,2,bs+1});
        }else if(zt==1){//横躺时
            q.push({x,y-1,0,bs+1});
            q.push({x,y+2,0,bs+1});
            q.push({x-1,y,1,bs+1});
            q.push({x+1,y,1,bs+1});
        }else{//竖躺时
        	q.push({x,y-1,2,bs+1});
            q.push({x,y+1,2,bs+1});
            q.push({x-1,y,0,bs+1});
            q.push({x+2,y,0,bs+1});
        }
    }
}
int main(){
    while(cin>>n>>m&&n&&m){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
		//手动加边界
        for(int i=1;i<=n;i++) a[i][0]='#',a[i][m+1]='#';
        for(int i=1;i<=m;i++) a[0][i]='#',a[n+1][i]='#';
        //找起点
        int f=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]=='X'){
                    if(a[i][j+1]=='X') st.zt=1;//起点是横躺状态
                    else if(a[i+1][j]=='X') st.zt=2;//起点是竖躺状态
                    else st.zt=0;//起点是直立状态
                    st.x=i,st.y=j;
					f=1;
					break;
                }
            }
            if(f) break;
        }
        //找终点
        f=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]=='O'){
                    if(a[i][j+1]=='O') ed.zt=1;//终点是横躺状态
                    else if(a[i+1][j]=='O') ed.zt=2;//终点是竖躺状态
                    else ed.zt=0;//终点是直立状态
                    ed.x=i,ed.y=j;
                    f=1;
					break;
                }
            }
            if(f) break;
        }

		std::cerr << "st " << st.x << " " << st.y << " " << st.zt << "\n";
		std::cerr << "ed " << ed.x << " " << ed.y << " " << ed.zt << "\n";

        bfs();//广搜
        if(ans==-1) cout<<"Impossible\n";//无解
        else cout<<ans<<"\n";//有解
        /*
        多测不清空
        爆零两行泪
        */
        memset(vis,0,sizeof(vis));
        ans=-1;
    }
    return 0;
}