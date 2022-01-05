// https://atcoder.jp/contests/abc208/tasks/abc208_d

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    int n, m;
    cin >> n >> m;

    long long dist[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dist[a - 1][b - 1] = c;
    }

    // 一番外のforはkで回すのに注意
    long long res = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                if (dist[i][j] < INF) res += dist[i][j];
            }
        }
    }

    cout << res << endl;
}