// https://atcoder.jp/contests/typical90/tasks/typical90_bq

#include <bits/stdc++.h>
using namespace std;

constexpr long long MOD = 1e9+7;

int binpower (long long a, long long b) {
	long long res = 1;
	while (b != 0) {
		if (b % 2 == 1) {
			res = (long long)(res)*a % MOD;
		}
		a = (long long)(a)*a % MOD;
		b /= 2;
	}
	return res;
}

int main () {
    long long n, k;
    cin >> n >> k;

    if (n == 1) cout << k << endl;
    else if (n == 2) cout << k*(k-1)%MOD << endl;
    else if (k <= 2) cout << 0 << endl;
    else cout << k*(k-1)%MOD*binpower(k-2, n-2)%MOD << endl;
}