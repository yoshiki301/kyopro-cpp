// https://atcoder.jp/contests/typical90/tasks/typical90_az

#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9+7;

int main () {
    int n;
    cin >> n;
    int a;
    vector<int> a_sum(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> a;
            a_sum[i] += a;
        }
    }

    long long res = 1;
    for (int i = 0; i < n; i++) {
        res *= a_sum[i];
        res %= MOD;
    }
    
    cout << res << endl;
}