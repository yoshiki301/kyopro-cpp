// https://atcoder.jp/contests/typical90/tasks/typical90_at

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    map<long long, long long> mod_a, mod_b, mod_ab;
    for (long long i = 0; i < 46; i++) {
        mod_a[i] = 0;
        mod_b[i] = 0;
        mod_ab[i] = 0;
    }

    // a, bを前処理しておけばO((46^2)*N)
    long long a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a;
        mod_a[a % 46] += 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> b;
        mod_b[b % 46] += 1;
    }
    for (long long i = 0; i < 46; i++) {
        for (long long j = 0; j < 46; j++) {
            mod_ab[(i + j) % 46] += (mod_a[i] * mod_b[j]);
        }
    }

    // c % 46 == 0のときに注意
    long long res = 0;
    for (int i = 0; i < n; i++) {
        cin >> c;
        res += mod_ab[(46 - (c % 46)) % 46];
    }

    cout << res << endl;
}