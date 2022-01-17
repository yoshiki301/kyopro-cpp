// https://atcoder.jp/contests/abc207/tasks/abc207_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int t;
    vector<double> l(n);
    vector<double> r(n);
    for (int i = 0; i < n; i++) {
        cin >> t >> l[i] >> r[i];
        if (t == 3 || t == 4) {
            l[i] += 0.1;
        }
        if (t == 2 || t == 4) {
            r[i] -= 0.1;
        }
    }

    // 全探索
    long long res = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (l[i] <= l[j] && l[j] <= r[i]) {
                res += 1;
            } else if (l[j] <= l[i] && r[i] <= r[j]) {
                res += 1;
            } else if (l[i] <= r[j] && r[j] <= r[i]) {
                res += 1;
            }
        }
    }
    cout << res << endl;
}