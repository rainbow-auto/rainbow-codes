#include "testlib.h"

const int MAXN = 2505;

std::vector<int> fri[MAXN];
int bel[MAXN], cnt[MAXN];

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);

	std::string pans = ouf.readWord();
	std::string jans = ans.readWord();

	if (pans == "rerender") {
		if (jans == "rerender")
			quitf(_ok, "OK (no solution)");
		else
			quitf(_wa, "You haven't found the solution.");
	}

	int n = inf.readInt();
	int m = inf.readInt();
	int p = inf.readInt();
	int q = inf.readInt();

	for (int i = 0; i < m; i++) {
		int u = inf.readInt();
		int v = inf.readInt();
		fri[u].push_back(v);
		fri[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		bel[i] = 0;

	int G = std::stoi(pans);
	for (int i = 1; i <= G; i++) {
		int g = ouf.readInt();
		if (g < 1 || g > p)
			quitf(_wa, "Group %d has %d members, but limit p is %d.", i, g, p);
		for (int j = 0; j < g; j++) {
			int x = ouf.readInt(1, n);
			if (bel[x] != 0)
				quitf(_wa, "Node %d belongs to more than one group.", x);
			bel[x] = i;
		}
	}

	for (int i = 1; i <= n; i++)
		if (bel[i] == 0)
			quitf(_wa, "Node %d isn't in a group.", i);

	for (int i = 1; i <= n; i++)
		for (int y : fri[i])
			if (bel[i] != bel[y])
				++cnt[bel[i]];

	for (int i = 1; i <= G; i++)
		if (cnt[i] > q)
			quitf(_wa, "Group %d has %d external edges, but limit q is %d.", i, cnt[i], q);

	if (jans == "rerender")
		quitf(_fail, "You have found a nonexistent solution.");

	quitf(_ok, "OK");
	return 0;
}
