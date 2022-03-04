// https://atcoder.jp/contests/typical90/tasks/typical90_bf

#include <bits/stdc++.h>
using namespace std;

constexpr long long MOD = 1e5;

long long operate(long long x) {
	long long res = x, y = x;
	while (y > 0) {
		res += (y % 10);
		y /= 10;
	}
	return res % MOD;
}

int main () {
	long long n, k;
	cin >> n >> k;
	
	set<long long> seen;
	vector<long long> z;

    // 高々1e5通りなので, ループを検知するところまで探せばよい
	while (seen.find(n) == seen.end()) {
		seen.insert(n);
		z.push_back(n);
		n = operate(n);
	}

	long long start;
	for (long long i = 0; i < (long long)z.size(); i++) {
		if (z[i] == n) {
			start = i;
			break;
		}
	}

	long long size = (long long)z.size();

	if (k <= size) cout << z[k] << endl;
	else {
		k -= size;
		k %= (size - start);
		cout << z[start + k] << endl;
	}
}