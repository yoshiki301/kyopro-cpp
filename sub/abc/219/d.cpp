// https://atcoder.jp/contests/abc219/tasks/abc219_d

#include <bits/stdc++.h>
using namespace std;

const int INF = 500;

int main () {
    int n, x, y;
    vector<int> a(n), b(n);
    cin >> n;
    cin >> x >> y;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    int dp[n+1][x+1][y+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k <= y; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;

    // 最小個数ナップサック
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k <= y; k++) {
                dp[i][min(j + a[i-1], x)][min(k + b[i-1], y)] = min(dp[i][min(j + a[i-1], x)][min(k + b[i-1], y)], dp[i-1][j][k] + 1);
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
            }
        }
    }

    if (dp[n][x][y] >= INF) {
        cout << -1 << endl;
    } else {
        cout << dp[n][x][y] << endl;
    }
}