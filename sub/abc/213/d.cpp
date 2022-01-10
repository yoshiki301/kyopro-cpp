// https://atcoder.jp/contests/abc213/tasks/abc213_d

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> res;

void dfs(int current, int prev) {
    res.push_back(current);
    for (int next : g[current]) {
        if (next != prev) {
            dfs(next, current);
            res.push_back(current);
        }
    }
}

int main() {
    int n;
    cin >> n;

    // オイラーツアーする
    g.resize(n);
    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    dfs(0, -1);
    for (int r : res) {
        cout << r + 1 << " ";
    }
    cout << endl;

}