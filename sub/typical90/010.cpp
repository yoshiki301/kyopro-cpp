// https://atcoder.jp/contests/typical90/tasks/typical90_j

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    int c;
    long long p;
    vector<long long> first(n, 0), second(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> c >> p;
        if (c == 1) {
            first[i] = p;
        } else {
            second[i] = p;
        }
    }

    vector<long long> cum_fisrt(n+1, 0), cum_second(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cum_fisrt[i] = cum_fisrt[i-1] + first[i-1];
        cum_second[i] = cum_second[i-1] + second[i-1];
    }

    int q;
    cin >> q;
    vector<int> l(q), r(q);
    for (int i = 0; i < q; i++) cin >> l[i] >> r[i];

    for (int i = 0; i < q; i++) {
        cout << cum_fisrt[r[i]] - cum_fisrt[l[i]-1] << " ";
        cout << cum_second[r[i]] - cum_second[l[i]-1] << endl;
    }
}