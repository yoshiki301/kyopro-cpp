// https://atcoder.jp/contests/abc220/tasks/abc220_d

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // dp[i][j] : 操作i回目のときに左がjとなる場合の数
    int dp[n][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][a[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][(j + a[i]) % 10] += dp[i-1][j];
            dp[i][(j + a[i]) % 10] %= MOD;
            dp[i][(j * a[i]) % 10] += dp[i-1][j];
            dp[i][(j * a[i]) % 10] %= MOD;
        }
    }

    for (int i = 0; i < 10; i++) cout << dp[n-1][i] << endl;
}