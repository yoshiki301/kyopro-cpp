// https://atcoder.jp/contests/typical90/tasks/typical90_d

#include <bits/stdc++.h>
using namespace std;

int main () {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> cum_h(h, 0), cum_w(w, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cum_h[i] += a[i][j];
        }
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cum_w[i] += a[j][i];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << cum_h[i] + cum_w[j] - a[i][j];
            if (j < w-1) cout << " ";
        }
        cout << endl;
    }
}