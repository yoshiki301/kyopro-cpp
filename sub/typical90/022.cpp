// https://atcoder.jp/contests/typical90/tasks/typical90_v

#include <bits/stdc++.h>
using namespace std;

int main () {
    long long a, b, c;
    cin >> a >> b >> c;

    // 最大公約数は__gcd(x, y)で計算できる
    long long g = __gcd(a, b);
    g = __gcd(g, c);

    long long res = (a/g) + (b/g) + (c/g) - 3;
    cout << res << endl;
}