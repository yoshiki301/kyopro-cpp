// https://atcoder.jp/contests/abc204/tasks/abc204_d

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n ; i++) cin >> t[i];

    int s = accumulate(t.begin(), t.end(), 0);

    // 部分和問題を解き, Tの総和の半分に最も近い部分和を求める
    bool dp[n + 1][2*s];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2*s; j++) {
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < s; j++) {
            if (dp[i-1][j] == true) {
                dp[i][j] = true;
                dp[i][j + t[i-1]] = true;
            }
        }
    }

    for (int j = s/2; j >= 0; j--) {
        if (dp[n][j] == true) {
            cout << s - j << endl;
            return 0;
        }
    }

}