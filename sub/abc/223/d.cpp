// https://atcoder.jp/contests/abc223/tasks/abc223_d

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // トポロジカルソートをしてなるべく辞書順で小さくなるように頂点を並べる
    vector<vector<int>> G(n);
    vector<int> indegree(n, 0);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a-1].push_back(b-1);
        indegree[b-1] += 1;
    }

    // 小さい順で取り出す優先度つきキュー
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }

    vector<int> res;
    while (!que.empty()) {
        int v = que.top();
        que.pop();

        for (const auto& neighbor : G[v]) {
            indegree[neighbor] -= 1;
            if (indegree[neighbor] == 0) que.push(neighbor);
        }

        res.push_back(v);
    }

    if ((int)res.size() == n) {
        for (const auto& r : res) {
            cout << r + 1 << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}