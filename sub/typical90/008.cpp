// https://atcoder.jp/contests/typical90/tasks/typical90_h

#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9+7;

int main () {
	int n;
	string s;
	cin >> n;
	cin >> s;

    // sのi文字目までで, 'atcoder'のj文字目までの作り方の総数がdp[i][j] (0-index)
	int dp[n][7];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 7; j++) dp[i][j] = 0;
	}

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (s[i] == 'a') dp[0][0] = 1;
		} else {
			for (int j = 0; j < 7; j++) dp[i][j] = dp[i-1][j];

			if (s[i] == 'a') {
				dp[i][0] += 1;
				dp[i][0] %= MOD;
			} else if (s[i] == 't') {
				dp[i][1] += dp[i][0];
				dp[i][1] %= MOD;
			} else if (s[i] == 'c') {
				dp[i][2] += dp[i][1];
				dp[i][2] %= MOD;
			} else if (s[i] == 'o') {
				dp[i][3] += dp[i][2];
				dp[i][3] %= MOD;
			} else if (s[i] == 'd') {
				dp[i][4] += dp[i][3];
				dp[i][4] %= MOD;
			} else if (s[i] == 'e') {
				dp[i][5] += dp[i][4];
				dp[i][5] %= MOD;
			} else if (s[i] == 'r') {
				dp[i][6] += dp[i][5];
				dp[i][6] %= MOD;
			}
		}
	}

	cout << dp[n-1][6] << endl;
}