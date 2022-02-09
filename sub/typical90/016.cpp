// https://atcoder.jp/contests/typical90/tasks/typical90_p

#include <bits/stdc++.h>
using namespace std;

constexpr long long MAX_N = 1e4;

int main () {
    long long n, a, b, c;
    cin >> n;
    cin >> a >> b >> c;

    long long res = MAX_N;
    for (long long i = 0; i < MAX_N; i++) {
        for (long long j = 0; i+j < MAX_N; j++) {
            // kが負になる場合に注意する
            long long k = (n - a*i - b*j) / c;
            if (a*i + b*j + c*k == n && k >= 0) {
                res = min(res, i+j+k);
            }
        }
    }
    cout << res << endl;
}