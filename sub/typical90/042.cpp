// https://atcoder.jp/contests/typical90/tasks/typical90_ap

#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9+7;

int main () {
	int k;
	cin >> k;

	// 1~9のみを用いて和がkになる組み合わせをdp[k]とする
	int dp[k+1];
	dp[0] = 1;

	if (k % 9 != 0) {
		cout << 0 << endl;
		return 0;
	} else {
		for (int i = 1; i <= k; i++) {
			dp[i] = 0;
			for (int j = 1; j <= 9; j++) {
				if (0 <= i - j) {
					dp[i] += dp[i-j];
					dp[i] %= MOD;
				}
			}
		}
	}
	cout << dp[k] << endl;
	
}