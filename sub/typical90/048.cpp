// https://atcoder.jp/contests/typical90/tasks/typical90_av

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    priority_queue<pair<long long, int>> que;
    for (int i = 0; i < n; i++) {
        que.push(make_pair(b[i], i));
    }

    // priority_queueでやったが, 上界を達成する方法が実現できる
    // 普通にsortしてもok
    long long res = 0;
    for (int i = 0; i < k; i++) {
        auto p = que.top();
        que.pop();
        res += p.first;
        if (p.first == b[p.second]) que.push(make_pair(a[p.second] - p.first, p.second));
    }

    cout << res << endl;
}