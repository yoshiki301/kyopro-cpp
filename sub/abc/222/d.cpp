// https://atcoder.jp/contests/abc222/tasks/abc222_d

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int b_max = b[n-1];

    // dp[i][j] : c_iがjになる場合の数
    int dp[n+1][b_max+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= b_max; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    // O(N*max(B))で計算
    for (int i = 1; i <= n; i++) {
        int l = a[i-1], u = b[i-1];
        int cumsum = 0;
        for (int j = 0; j <= u; j++) {
            cumsum += dp[i-1][j];
            cumsum %= MOD;
            if (j >= l) {
                dp[i][j] += cumsum;
                dp[i][j] %= MOD;
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i <= b_max; i++) {
        res += dp[n][i];
        res %= MOD;
    }
    cout << res << endl;
}