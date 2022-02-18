// https://atcoder.jp/contests/typical90/tasks/typical90_bw

#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> prime_factorize(long long n) {
	vector<pair<long long, long long>> res;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i != 0) continue;
		long long e = 0;
		while (n % i == 0) {
			e += 1;
			n /= i;
		}
		res.push_back({i, e});
	}
	if (n != 1) res.push_back({n, 1});
    return res;
}

int main () {
    long long n;
	cin >> n;
	vector<pair<long long, long long>> pf = prime_factorize(n);
	long long count = 0;
	for (const auto& [i, e] : pf) {
		count += e;
	}

	cout << (long long)ceil(log2(count)) << endl;
}