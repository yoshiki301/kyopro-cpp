// https://atcoder.jp/contests/abc235/tasks/abc235_c

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, q;
    cin >> n >> q;

    map<long long, vector<int>> a_mem;
    long long a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        a_mem[a].push_back(i+1);
    }
    vector<long long> x(q), k(q);
    for (int i = 0; i < q; i++) cin >> x[i] >> k[i];

    for (int i = 0; i < q; i++) {
        if (a_mem[x[i]].size() < k[i]) {
            cout << -1 << endl;
        } else {
            cout << a_mem[x[i]][k[i]-1] << endl;
        }
    }
}