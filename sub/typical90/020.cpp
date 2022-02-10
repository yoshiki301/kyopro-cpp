// https://atcoder.jp/contests/typical90/tasks/typical90_t

#include <bits/stdc++.h>
using namespace std;

int main () {
    long long a, b, c;
    cin >> a >> b >> c;

    // なるべく整数で計算する
    long long pow = 1;
    for (int i = 0; i < b; i++) pow *= c;
    if (a < pow) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}