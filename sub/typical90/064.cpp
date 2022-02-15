// https://atcoder.jp/contests/typical90/tasks/typical90_bl

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n), diff(n-1);
    vector<long long> l(q), r(q), v(q);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i] >> v[i];
    }

    long long score = 0;
    for (int i = 0; i < n-1; i++) {
        diff[i] = a[i+1] - a[i];
        score += abs(diff[i]);
    }
    
    for (int i = 0; i < q; i++) {
        if (l[i] > 1) {
            score -= abs(diff[l[i]-2]);
            diff[l[i]-2] += v[i];
            score += abs(diff[l[i]-2]);
        }
        if (r[i] < n) {
            score -= abs(diff[r[i]-1]);
            diff[r[i]-1] -= v[i];
            score += abs(diff[r[i]-1]);
        }
        cout << score << endl;
    }
    
}