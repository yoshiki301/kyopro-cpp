// https://atcoder.jp/contests/typical90/tasks/typical90_bi

#include <bits/stdc++.h>
using namespace std;

int main () {
    int q;
    cin >> q;
    vector<int> t(q), x(q);
    for (int i = 0; i < q; i++) cin >> t[i] >> x[i];

    // dequeを使えば先頭, 末尾両方にinsertできる
    // 今回は2つのvectorで管理
    vector<int> top, bottom;
    for (int i = 0; i < q; i++) {
        if (t[i] == 1) {
            top.push_back(x[i]);
        } else if (t[i] == 2) {
            bottom.push_back(x[i]);
        } else {
            if ((int)top.size() >= x[i]) {
                int top_index = (int)top.size() - x[i];
                cout << top[top_index] << endl;
            } else {
                int bottom_index = x[i] - (int)top.size() - 1;
                cout << bottom[bottom_index] << endl;
            }
        }
    }
}