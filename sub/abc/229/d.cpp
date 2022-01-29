// https://atcoder.jp/contests/abc229/tasks/abc229_d

#include <bits/stdc++.h>
using namespace std;

int main () {
    string x;
    int k;
    cin >> x;
    cin >> k;

    int n = x.size();
    int count_blank[n + 1];
    count_blank[0] = 0;
    for (int i = 0; i < n; i++) {
        count_blank[i+1] = count_blank[i] + (x[i] == '.' ? 1 : 0);
    }

    // しゃくとり法
    // for + whileだと簡単に書ける
    int l, r;
    int res = 0;
    for (l = 0; l < n; l++) {
        while (r < n && count_blank[r+1] - count_blank[l] <= k) {
            r += 1;
        }
        res = max(res, r - l);
    }
    cout << res << endl;
}