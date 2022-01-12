// https://atcoder.jp/contests/abc217/tasks/abc217_d

#include <bits/stdc++.h>
using namespace std;

int main () {
    long long l, q;
    cin >> l >> q;
    vector<pair<int, long long>> queries(q);
    for (auto& query : queries) cin >> query.first >> query.second;
    
    // 切った箇所をsetで記憶し, 二分探索で木の長さを取得
    // どちらのクエリもO(log(N))
    set<long long> cut = {0, l};
    for (const auto& [c, x] : queries) {
        if (c == 1) {
            cut.insert(x);
        } else {
            auto iter = cut.lower_bound(x);
            cout << *iter - *(--iter) << endl;
        }
    }
}