// https://atcoder.jp/contests/typical90/tasks/typical90_al

#include <bits/stdc++.h>
using namespace std;

constexpr long long MAX = 1e18;

int main () {
    long long a, b;
    cin >> a >> b;

    long long g = __gcd(a, b);
    long long a_prime = a/g;
    long long b_prime = b/g;

    // オーバーフローに注意
    if (MAX / a_prime / b_prime / g < 1) {
        cout << "Large" << endl;
    } else {
        cout << a_prime * b_prime * g << endl;
    }
}