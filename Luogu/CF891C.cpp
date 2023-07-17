#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 500005;

struct Edge {
	int u, v, w, id;	
		
	int fa_u, fa_v;	
		
	friend bool operator < (Edge a, Edge b) {
		return a.w < b.w;
	}
}; 

Edge g[maxn];
Edge e[maxn];

int n, m;

bool sort_by_id (Edge a, Edge b) {
	return a.id < b.id;
}

int fa[maxn];

int find (int x) {
	if (fa[x] == x) {
		return fa[x];
	} else {
		return fa[x] = find (fa[x]);
	}
}

inline void merge (int x, int y) {
	fa[find(x)] = find(y);
}

int main () {
//	fastread
	
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf ("%d", &u);
		scanf ("%d", &v);
		scanf ("%d", &w);
		g[i] = Edge{u, v, w, i, 0, 0};
	}
	
	for (int i = 1; i <= n; i++) fa[i] = i; // init
	
	sort (g + 1, g + m + 1);
	
	g[0].w = -1;
	int start = 1;
	while (start <= m) {
		int now = start;
		do {
			g[now].fa_u = find(g[now].u);
			g[now].fa_v = find(g[now].v);
			now ++;		
		} while (now <= m and g[now].w == g[now - 1].w); // �Ѿ�����ͬȨֵ������, ֱ��find 
		
		while (start < now) {
			while (start < now and find(g[start].u) == find(g[start].v)) {
				start ++; // �ӱ��Ժ������, ����ֱ���ӹ� 
			}
			if (start < now) {
				merge (g[start].u, g[start].v);
			}
		}		
	}
		
	sort (g + 1, g + m + 1, sort_by_id);	
	
	for (int i = 1; i <= n; i++) fa[i] = i; // ��Ϊ���鼯�е�ֵ�Ѿ�����������
	
	int T; cin >> T;
	
	while (T--) {
		int count; scanf("%d", &count);
		
		vector<Edge> e;	
		for (int i = 1; i <= count; i++) {
			int id; scanf("%d", &id);
			e.push_back(Edge{g[id].fa_v, g[id].fa_u, g[id].w, i, 0, 0});
		}
	
		sort (e.begin(), e.end()); // �����ʱ��ҲҪ�� $w$ ���� 
	
		bool flag = true;
		
		int k = e.size() - 1;
		int start = 0; 
		while (start <= k and flag == true) {
			if (flag == false) break;
			
			if (e[start].u == e[start].v) { // �Ի�, ������ 
				flag = false;
				break;
			} 
			
			merge (e[start].u, e[start].v);			
			
			int now = start + 1;
			
			while (now <= k and e[now].w == e[start].w) { // ����ÿһ�� $w$ ��ͬ��ѯ�ʱ�, ���Լӽ�ȥ 
				if (find(e[now].u) == find(e[now].v)) { // �Ӳ���ȥ˵��ʧ��
					flag = false;
					break;
				}
				merge (e[now].u, e[now].v);								
				now ++;
			}
			
			while (start < now) { // ��ԭ 
				fa[e[start].u] = e[start].u;
				fa[e[start].v] = e[start].v; 
				start ++;
			}			
		}		
		
		if (flag) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}		
		
	return 0;
}
