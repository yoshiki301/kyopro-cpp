// https://atcoder.jp/contests/abc227/tasks/abc227_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    // ループ条件を工夫する
    long long res = 0;
    for (long long a = 1; a*a*a <= n; a++) {
        for (long long b = a; a*b*b <= n; b++) {
            res += n/a/b - b + 1;
        }
    }

    cout << res << endl;
}