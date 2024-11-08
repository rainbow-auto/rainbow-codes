#include <iostream>

using namespace std;

const int maxn = 15;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

int a[maxn][maxn];

struct Block {
    int x, y;
    int d, len; // direct | length
    int id;
};

vector<Block> b;

inline void move (int id, int len) {
    b[id].x += dx[d] * len;
    b[id].y += dy[d] * len;
}

bool check () { // 是否有重叠的
    int t[maxn][maxn]; memset (t, 0, sizeof (t));
    for (auto now : b) {
        int nowx = now.x;
        int nowy = now.y;
        for (int i = 1; nowx <= n and nowy <= n and i <= now.len; i++) {
            if (t[nowx][nowy]) { return false; }
            t[nowx][nowy] = now.id;
            nowx += dx[now.d];
            nowy += dy[now.d];
        }
    } 
    return true;
}

Block find (int x, int y) {
    int t[maxn][maxn]; memset (t, 0, sizeof (t));

    for (auto now : b) {
        int nowx = now.x;
        int nowy = now.y;

        for (int i = 1; nowx <= n and nowy <= n and i <= now.len; i++) {
            t[nowx][nowy] = now.id;
            nowx += dx[now.d];
            nowy += dy[now.d];
        }
    }

    return t[x][y];
}

void dfs (int x, int y, int step) {
    Block now = find (x, y);
    move (now.id, )
}

int main () {
    
    return 0;
}   