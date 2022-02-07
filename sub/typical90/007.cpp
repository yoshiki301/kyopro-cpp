// https://atcoder.jp/contests/typical90/tasks/typical90_g

#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    long long q;
    cin >> q;
    vector<long long> b(q);
    for (long long i = 0; i < q; i++) cin >> b[i];

    for (long long i = 0; i < q; i++) {
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        if (it == a.begin()) cout << abs(a[0] - b[i]) << endl;
        else if (it == a.end()) cout << abs(a[n-1] - b[i]) << endl;
        else {
            int index = distance(a.begin(), it);
            long long  res = min(abs(a[index-1] - b[i]), abs(a[index] - b[i]));
            cout << res << endl;
        }
    }

}