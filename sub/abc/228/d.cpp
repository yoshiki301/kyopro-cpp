// https://atcoder.jp/contests/abc228/tasks/abc228_d

// TODO: AC

#include <bits/stdc++.h>
using namespace std;

// コンパイル時定数
constexpr int N = 1<<20; 

int main() {
    int q;
    cin >> q;

    vector<long long> t(q), x(q);
    for (int i = 0; i < q; i++) cin >> t[i] >> x[i];

    vector<long long> a(N, -1);
    vector<long long> seen_index;

    for (int i = 0; i < q; i++) {
        long long h = (x[i] % N);

        if (t[i] == 1) {
            if (a[h] != -1) {
                auto it = lower_bound(seen_index.begin(), seen_index.end(), h);
                a[*it + 1] = x[i];
                seen_index.push_back(*it + 1);
            } else {
                a[h] = x[i];
                seen_index.push_back(h);
            }
            sort(seen_index.begin(), seen_index.end());
        } else {
            cout << a[h] << endl;
        }
    }
}