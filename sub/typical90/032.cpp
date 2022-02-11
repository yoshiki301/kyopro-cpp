// https://atcoder.jp/contests/typical90/tasks/typical90_af

#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_TIME = 1e4 + 1;

int main () {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int m;
    cin >> m;
    vector<vector<int>> xy(n, vector<int>(n, 0));
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        xy[x-1][y-1] = 1;
        xy[y-1][x-1] = 1;
    }

    // 制約が小さいので順列全探索
    vector<int> runner;
    for (int i = 0; i < n; i++) runner.push_back(i);

    int res = MAX_TIME;
    do {
        bool valid = true;
        for (int i = 0; i < n-1; i++) {
            if (xy[runner[i]][runner[i+1]] == 1) valid = false;
        }
        if (valid) {
            int time = 0;
            for (int i = 0; i < n; i++) time += a[runner[i]][i];
            res = min(res, time);
        }
    } while (next_permutation(runner.begin(), runner.end()));

    if (res == MAX_TIME) cout << -1 << endl;
    else cout << res << endl;
}