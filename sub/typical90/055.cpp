// https://atcoder.jp/contests/typical90/tasks/typical90_bc

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 定数倍でO(N^5)が間に合う
    // max N = 100だが, ループ回数が(N^5)/120のため
    int res = 0;
    for (int i = 0; i < n-4; i++) {
        for (int j = i+1; j < n-3; j++) {
            for (int k = j+1; k < n-2; k++) {
                for (int l = k+1; l < n-1; l++) {
                    for (int m = l+1; m < n; m++) {
                        long long prod = a[i];
                        prod *= a[j];
                        prod %= p;
                        prod *= a[k];
                        prod %= p;
                        prod *= a[l];
                        prod %= p;
                        prod *= a[m];
                        prod %= p;
                        if (prod == q) res += 1;
                    }
                }
            }
        }
    }

    cout << res << endl;
}