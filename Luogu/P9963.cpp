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
#include <iomanip>

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

int main () {
	fastread

	i64 n, l, r;
	f64 p;

	std::cin >> n >> p >> l >> r;

	std::cout << std::fixed << std::setprecision (10) << p * (r - l + 1) << "\n";

	return 0;
}
