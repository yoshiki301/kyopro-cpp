// https://atcoder.jp/contests/abc232/tasks/abc232_d

#include <bits/stdc++.h>
using namespace std;

int main () {
    int h, w;
    cin >> h >> w;

    vector<string> c(h);
    for (int i = 0; i < h; i++) cin >> c[i];

    int dist[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            dist[i][j] = -1;
        }
    }
    dist[0][0] = 1;

    int res = 1;
    queue<pair<int, int>> que;
    vector<pair<int, int>> diff;
    diff.push_back(make_pair(1,0));
    diff.push_back(make_pair(0,1));
    que.push(make_pair(0, 0));
    while (!que.empty()) {
        pair<int, int> current = que.front();
        que.pop();
        int x = current.first;
        int y = current.second;
        for (const auto& [dx, dy] : diff) {
            if (x + dx < h && y + dy < w) {
                if (c[x + dx][y + dy] == '.' && dist[x][y] + 1 > dist[x + dx][y + dy]) {
                    dist[x + dx][y + dy] = dist[x][y] + 1;
                    res = max(res, dist[x + dx][y + dy]);
                    que.push(make_pair(x + dx, y + dy));
                }
            }
        }
    }
    cout << res << endl;
}