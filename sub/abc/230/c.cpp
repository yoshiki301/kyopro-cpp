// // https://atcoder.jp/contests/abc230/tasks/abc230_c

#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, a, b;
    cin >> n >> a >> b;
    long long p, q, r, s;
    cin >> p >> q >> r >> s;

    for (long long i = p; i <= q; i++) {
        for (long long j = r; j <= s; j++) {
            if (abs(i - a) == abs(j - b)) {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
}