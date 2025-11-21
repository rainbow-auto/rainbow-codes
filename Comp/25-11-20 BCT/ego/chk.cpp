#include "testlib.h"
#include <cmath>
#include <numeric>
#include <vector>

int main(int argc, char *argv[]) {
	registerLemonChecker(argc, argv);

	int n = inf.readInt(2, 50, "n");
	int m = inf.readInt(1, 10, "m");
	inf.readEoln();

	std::vector<std::vector<int>> poles(n + 2);

	for (int i = 1; i <= n; ++i) {
		poles[i].resize(m);
		for (int j = 0; j < m; ++j) {
			poles[i][j] = inf.readInt(1, n + 2, "c_i_j");
			if (j < m - 1) {
				inf.readSpace();
			}
		}
		inf.readEoln();
	}

	long long k = ouf.readInt(0, 1000000, "k");

	for (long long i = 1; i <= k; ++i) {
		int x = ouf.readInt(0, n + 1, "x");
		int y = ouf.readInt(0, n + 1, "y");

		if (std::abs(x - y) != 1) {
			quitf(_wa, "Move %lld: poles %d and %d are not adjacent.", i, x, y);
		}

		if (poles[x].empty()) {
			quitf(_wa, "Move %lld: source pole %d is empty.", i, x);
		}

		if (int(poles[y].size()) >= m) {
			quitf(_wa, "Move %lld: destination pole %d is full (capacity is %d).", i, y, m);
		}

		int ball_color = poles[x].back();
		poles[x].pop_back();
		poles[y].push_back(ball_color);
	}

	for (int i = 0; i <= n + 1; ++i) {
		if (poles[i].size() <= 1) {
			continue;
		}

		int first_color = poles[i][0];
		for (size_t j = 1; j < poles[i].size(); ++j) {
			if (poles[i][j] != first_color) {
				quitf(_wa, "Final state is incorrect: pole %d contains balls of different colors.", i);
			}
		}
	}

	quitf(_ok, "Correct solution with %lld moves.", k);

	return 0;
}
