// https://atcoder.jp/contests/abc218/tasks/abc218_d

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<pair<long long, long long>> coord;
    long long x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coord.insert(make_pair(x, y));
    }

    // 全探索でO(N^2logN)
    long long res = 0;
    for (const auto& [x1, y1] : coord) {
        for (const auto& [x2, y2]: coord) {
            if (x1 != x2 && y1 != y2) {
                auto iter1 = coord.find(make_pair(x1, y2));
                auto iter2 = coord.find(make_pair(x2, y1));
                if (iter1 != coord.end() && iter2 != coord.end()) {
                    res += 1;
                }
            }
        }
    }
    res /= 4;
    cout << res << endl;
}