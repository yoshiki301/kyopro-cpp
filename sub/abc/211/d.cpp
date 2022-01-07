// https://atcoder.jp/contests/abc211/tasks/abc211_d

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main () {
    int n, m;
    cin >> n >> m;

    vector<long long> cost(n, -1);
    vector<long long> pattern(n, 0);
    cost[0] = 0;
    pattern[0] = 1;

    vector<vector<int>> g(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    // 辺のコストは同じのため, queueで訪れる頂点を管理すればよい
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (const auto& neighbor : g[x]) {
            if (cost[neighbor] == -1) {
                cost[neighbor] = cost[x] + 1;
                pattern[neighbor] = pattern[x];
                q.push(neighbor);
            } else if (cost[x] + 1 == cost[neighbor]) {
                pattern[neighbor] += pattern[x];
                pattern[neighbor] %= MOD;
            }
        }
    }
    long long res = pattern[n-1] == -1 ? 0 : pattern[n-1];
    cout << res << endl;

}