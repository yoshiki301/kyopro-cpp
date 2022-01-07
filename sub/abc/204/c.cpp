// https://atcoder.jp/contests/abc204/tasks/abc204_c

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2000;

bool seen[MAX_N];
vector<vector<int>> ab;

void dfs (int v) {
    if (seen[v]) return;
    seen[v] = true;
    for (const auto& dist : ab[v]) {
        dfs(dist);
    }
}

int main () {
    int n, m;
    cin >> n >> m;

    // resizeが必要
    ab.resize(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        ab[a-1].push_back(b-1);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) seen[j] = false;
        dfs(i);
        for (int j = 0; j < n; j++) if (seen[j]) res += 1;
    }

    cout << res << endl;
}