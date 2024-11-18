#include <bits/stdc++.h>
#define rep(_I, _ST, _ED) for (int _I = (_ST); _I <= (_ED); _I++)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";

const int maxn = 55;
const int inf = 0x3f3f3f3f;
int n, m;
struct State {
	int rd, rx, ry;//robot_d,x,y
};

//............N..E..S..W
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, 1, 0, -1 };
int F[4][maxn][maxn];
bool map[maxn][maxn];
//0-N 1-E 2-S 3-W

inline int moddic(int d) { return (d+4)%4; }

inline int dictonum(char dic) {
	if(dic=='N') return 0;
	if(dic=='E') return 1;
	if(dic=='S') return 2;	
	if(dic=='W') return 3; 
	dbg(dic);
	assert(0);
}

//x,y为左上坐标
inline bool check(int x,int y) {
	//边界及机器人体积 
	if (not (x >= 1 and y >= 1 and x < n and y < m)) return false;
	//障碍 
	if (map[x][y] + map[x + 1][y] + map[x][y + 1] + map[x + 1][y + 1]) return false;
	return true;
}

inline bool chkmin(int& x, int y) { return x > y ? x = y, 1 : 0; }

inline void bfs(int sd, int sx, int sy) {
	std::memset(F, 0x3f, sizeof F);
	F[sd][sx][sy] = 0;

	std::queue<State> q;
	q.push(State { sd, sx, sy });
	
	while (not q.empty()) {
		int d = q.front().rd;
		int x = q.front().rx;
		int y = q.front().ry;
		q.pop();
		
		if(not check(x, y))continue;
		rep (stp, 1, 3) {
			int nx = x + stp * mx[d];
			int ny = y + stp * my[d];
			if (not check(nx, ny)) break;
			if (chkmin(F[d][nx][ny], F[d][x][y] + 1)) q.push(State { d, nx, ny });
		}

		if (chkmin(F[moddic(d + 1)][x][y], F[d][x][y] + 1)) q.push(State { moddic(d + 1), x, y });
		if (chkmin(F[moddic(d - 1)][x][y], F[d][x][y] + 1)) q.push(State { moddic(d - 1), x, y });
	}
}

int main() {
	std::cin >> n >> m;
	rep (i, 1, n) rep (j, 1, m) std::cin >> map[i][j];

	char dic;
	int x, y, mxx, myy;
	std::cin >> x >> y >> mxx >> myy;
	std::cin >> dic;

	bfs(dictonum(dic), x, y);
	
	int ans; std::memset(&ans, 0x3f, sizeof ans);
	rep (d, 0, 3) ans = std::min(ans, F[d][mxx][myy]);

	ans = (ans == inf) ? -1 : ans;
	std::cout << ans << "\n";
	return 0;
}