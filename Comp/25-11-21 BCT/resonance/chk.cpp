#include "testlib.h"

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	int n = inf.readInt();
	int k = inf.readInt();
	std::vector<int> a = inf.readInts(n);
	std::vector<int> b = inf.readInts(n);
	std::vector<int> final(n);
	long long pans = ouf.readLong();
	long long jans = ans.readLong();
	if (pans > jans)
		quitf(_wa, "expect %lld, but found %lld", jans, pans);
	std::string psol = ouf.readToken("[AB]+");
	if (psol.length() != n)
		quitf(_wa, "wrong solution");
	int cntA = 0;
	for (int i = 0; i < n; i++)
	{
		if (psol[i] == 'A') ++cntA;
		final[i] = psol[i] == 'A' ? a[i] : b[i];
	}
	quitif(cntA != k, _wa, "wrong solution");
	long long s = 0, sol = 0;
	for (int i = 0; i < n; i++)
	{
		s = s > 0 ? s + final[i] : final[i];
		sol = std::max(sol, s);
	}
	quitif(sol != pans, _wa, "wrong solution");
	if (pans < jans)
		quitf(_fail, "wrong checker");
	quitf(_ok, "ok");
	return 0;
}
