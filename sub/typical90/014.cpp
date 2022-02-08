// https://atcoder.jp/contests/typical90/tasks/typical90_n

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // 交差しないように結び付ければよい
    // 2つを昇順にソートして差の絶対値を足し合わせる
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long res = 0;
    for (int i = 0; i < n; i++) res += abs(a[i] - b[i]);
    cout << res << endl;
}