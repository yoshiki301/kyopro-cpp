// https://atcoder.jp/contests/typical90/tasks/typical90_x

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k;
    cin >> n >> k;

    vector<int> diff(n);
    for (int i = 0; i < n; i++) cin >> diff[i];
    int b, diff_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> b;
        diff_sum += abs(diff[i] - b);
    }

    // パリティを考える
    // 最低限必要な操作回数 <= kかつ, その差が偶数であればYes
    if (diff_sum <= k && (k - diff_sum) % 2 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}