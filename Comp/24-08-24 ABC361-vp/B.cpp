#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

struct Point {
	int pos[3];
	inline void read () {
		rep (i, 0, 2) { std::cin >> pos[i]; }
	}

	friend bool operator == (Point a, Point b) {
		rep (i, 0, 2) { if (a.pos[i] != b.pos[i]) { return false; } }
		return true;
	}

	friend bool operator != (Point a, Point b) { return not (a == b); }
};

struct Rect {
	Point p[2];

	inline void adjust () {
		int x0 = std::min (p[0].pos[0], p[1].pos[0]);
		int y0 = std::min (p[0].pos[1], p[1].pos[1]);
		int z0 = std::min (p[0].pos[2], p[1].pos[2]);
		
		int x1 = std::max (p[0].pos[0], p[1].pos[0]);
		int y1 = std::max (p[0].pos[1], p[1].pos[1]);
		int z1 = std::max (p[0].pos[2], p[1].pos[2]);

		p[0] = Point { x0, y0, z0 };
		p[1] = Point { x1, y1, z1 };
	}

	friend bool operator == (Rect x, Rect y) {
		rep (i, 0, 1) {
			if (x.p[i] != y.p[i]) { return false; }
		}
		return true;
	}

	inline void read () {
		p[0].read (); p[1].read ();
	}
} a, b;

inline bool inside (Point x, Rect r) {
	bool res = true;
	rep (i, 0, 2) {
		res &= (r.p[0].pos[i] < x.pos[i] and x.pos[i] <= r.p[1].pos[i]);
	}
	return res;
}

inline bool chk (Rect a, Rect b) {
	if (a == b) { return true; }

	bool res = false;
	rep (i, 0, 1) {
		rep (j, 0, 1) {
			rep (k, 0, 1) {
				res |= inside (Point { a.p[i].pos[0], a.p[j].pos[1], a.p[k].pos[2] }, b);
			}
		}
	}

	rep (i, 0, 1) {
		rep (j, 0, 1) {
			rep (k, 0, 1) {
				res |= inside (Point { b.p[i].pos[0], b.p[j].pos[1], b.p[k].pos[2] }, a);
			}
		}
	}

	return res;
}

bool MemED;
int main () {
	fastread
	// lookMem	

	a.read (); a.adjust ();
	b.read (); b.adjust ();

	if (chk (a, b)) { std::cout << "Yes\n"; }
	else { std::cout << "No\n"; }

	return 0;
}
