#include <bits/stdc++.h>
using namespace std;

const int INF = 1LL << 30;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> g(n);
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    int c[q], d[q];
    for (int i = 0; i < q; i++) {
        cin >> c[i] >> d[i];
    }

    // 二部グラフの頂点の2色の色分けとして解く
    vector<int> color(n, -1);
    queue<int> que;
    que.push(0);
    color[0] = 0;
    while (!que.empty()) {
        int idx = que.front();
        que.pop();
        for (int neighbor : g[idx]) {
            if (color[neighbor] == -1) {
                color[neighbor] = color[idx] + 1;
                que.push(neighbor);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        if ((color[c[i]-1] - color[d[i]-1]) % 2 == 0) {
            cout << "Town" << endl;
        } else {
            cout << "Road" << endl;
        }
    }
}