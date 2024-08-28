#include <bits/stdc++.h>
// #pragma GCC optimize(2)

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

i64 p, a, b, x1, t;
struct Matrix {
	i64 mat[2][2];
	i64* operator [] (int i) { return mat[i]; }

	friend Matrix operator * (Matrix a, Matrix b) {
		Matrix res;
		res[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % p;
		res[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % p;
		res[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % p;
		res[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % p;
		return res;
	}
};

constexpr Matrix e = Matrix { { { 1, 0 }, { 0, 1 } } };

inline Matrix ksm (Matrix a, i64 b) {
	Matrix res = e;
	while (b) {
		if (b & 1) { res = res * a; }
		a = a * a; b >>= 1;
	}
	return res;
}

Matrix A;
Matrix B;
Matrix C;

std::unordered_map <i64, i64> R;
inline i64 bsgs () { // A ^ x * B = C
	R.clear ();
	i64 m = (i64) sqrt (p) + 1;
	rep (j, 0, m) {
		Matrix curr = ksm (A, j) * C;
		R[curr[0][0]] = j; // j 取最大 => 最小化 i * m - j
	}

	Matrix s = ksm (A, m);
	Matrix pw = s;
	rep (i, 1, m) {
		Matrix curr = pw * B;
		pw = pw * s;
		if (R.find (curr[0][0]) == R.end ()) { continue; }
		i64 j = R[curr[0][0]];
		return (i * m - j) + 1; // 特殊
	}

	return -1;
}

inline i64 solve () {
	if (not a) {
		if (t == x1) { return 1; }
		if (t == b) { return 2; }
		return -1;
	}
	
	A[0][0] = a; A[0][1] = b;
	A[1][0] = 0; A[1][1] = 1;

	B[0][0] = x1; B[1][0] = 1;

	C[0][0] = t; C[1][0] = 1;

	return bsgs ();
}

inline i64 read () {
	char ch = getchar ();
	i64 res = 0;
	while (not isdigit (ch)) { ch = getchar (); }
	while (isdigit (ch)) { res = res * 10ll + ch - '0'; ch = getchar (); }
	return res;
}

bool MemED;
int main () {
	// fastread
	// lookMem	

	int T; std::cin >> T;
	while (T--) {
		// std::cin >> p >> a >> b >> x1 >> t;
		p = read (); a = read (); b = read (); x1 = read (); t = read ();

		std::cout << solve () << "\n";
	}

	return 0;
}
