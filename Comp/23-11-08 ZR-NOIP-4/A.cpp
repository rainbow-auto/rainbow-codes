#include <iostream>

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

int n, m;

namespace Subtask1 {
	
	inline void solve () {
        int dx = 1;
        int dy = 1;
        
		int t = 1;
		int nowx = 0 + dx;
		int nowy = 0 + dy;
		
        while (nowx or nowy) {
            if (nowx == n or nowx == 0) { dx *= -1; }
			if (nowy == m or nowy == 0) { dy *= -1; }
			nowx += dx;
			nowy += dy;
			t++;
		}

		std::cout << t << "\n";
	}
}

namespace Subtask2 {
    inline void solve () {
        std::cout << (n << 1) << "\n";
    }
}

namespace Subtask3 {
    inline void solve () {
        std::cout << (m << 1) << "\n";
    }
}

int main () {
	fastread

	int Q; std::cin >> Q;

	while (Q--) {
		std::cin >> n >> m;

		if (n == m) { Subtask2::solve (); }
		else if (n == 1) { Subtask3::solve (); }
		else { Subtask1::solve (); }
	}

	return 0;
}
