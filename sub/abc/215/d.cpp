// https://atcoder.jp/contests/abc215/tasks/abc215_d

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

int main() {
    int n, m;
    cin >> n >> m;

    bool exist[MAX_N + 1];
    for (int i = 0; i <= MAX_N; i++) exist[i] = false;

    // Aに含まれる素因数をsetで記憶しふるいで落とす
    int a;
    set<int> primes;
    for (int i = 0; i < n; i++) {
        cin >> a;
        double end = sqrt(a);
        for (int j = 2; j <= end; j++) {
            while (a % j == 0) {
                primes.insert(j);
                a /= j;
            }
            if (a == 1) break;
        }
        if (a != 1) {
            primes.insert(a);
        }
    }

    // setに対する範囲forは昇順で取り出せる
    for (const auto& p : primes) {
        for (int i = p; i <= MAX_N; i += p) exist[i] = true;
    }

    vector<int> res;
    for (int i = 1; i <= m; i++) {
        if (!exist[i]) res.push_back(i);
    }
    cout << res.size() << endl;
    for (const auto& r : res) cout << r << endl;

}