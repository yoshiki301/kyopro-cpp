// https://atcoder.jp/contests/abc211/tasks/abc211_c

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main () {
    string s;
    cin >> s;

    string t = "chokudai";
    int n = s.size();
    vector<vector<long long>> dp(n+1, vector<long long>(9));
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            if (s[i] != t[i]) {
                dp[i+1][j+1] = dp[i][j+1];
            } else {
                dp[i+1][j+1] = dp[i][j+1] + dp[i][j];
            }
            dp[i+1][j+1] %= MOD;
        }
    }
    cout << dp[n][8] << endl;
}