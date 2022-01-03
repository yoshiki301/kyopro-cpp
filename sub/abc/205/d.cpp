// https://atcoder.jp/contests/abc205/tasks/abc205_d

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n+1), k(q);
    vector<long long> c(n+1);

    a[0] = 0;
    c[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (i == 1) {
            c[i] = a[i] - 1;
        } else {
            c[i] = a[i] - a[i-1] - 1 + c[i-1];
        }
    }
    for (int i = 0; i < q; i++) cin >> k[i];

    // lower_boundで返されるのはイテレータ
    // インデックスに変換するにはstd::distanceを使う
    for (const auto& query: k) {
        if (query > c[n]) {
            cout << a[n] + (query - c[n]) << endl;
        } else {
            auto iter = lower_bound(c.begin(), c.end(), query);
            int i = distance(c.begin(), iter);
            cout << (a[i] - 1) - (c[i] - query) << endl;
        }
    }

}