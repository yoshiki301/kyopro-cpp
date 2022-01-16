// https://atcoder.jp/contests/abc206/tasks/abc206_c

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    map<long long, long long> a_map;
    long long a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        a_map[a]++;
    }

    long long res = 0;
    for (const auto& ai : a_map) {
        res += ((long long)n - ai.second) * ai.second;
    }
    res /= 2;
    cout << res << endl;
}