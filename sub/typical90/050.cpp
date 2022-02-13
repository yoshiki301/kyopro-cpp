// https://atcoder.jp/contests/typical90/tasks/typical90_ax

#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9+7;

int main () {
    int n, l;
    cin >> n >> l;

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        dp[i+1] += dp[i];
        dp[i+1] %= MOD;
        if (i+l <= n) {
            dp[i+l] += dp[i];
            dp[i+l] %= MOD;
        }
    }

    cout << dp[n] << endl;
}