// https://atcoder.jp/contests/typical90/tasks/typical90_r

#include <bits/stdc++.h>
using namespace std;

constexpr long double PI = 2.0*asin(1.0);

int main () {
    long double t, l, x, y, q;
    cin >> t;
    cin >> l >> x >> y;
    cin >> q;
    vector<long double> e(q);
    for (long double i = 0; i < q; i++) cin >> e[i];

    for (long double i = 0; i < q; i++) {
        long double rotate_rad = 2.0*PI*(e[i]/t);
        long double wheel_y = -(l/2.0)*sin(rotate_rad);
        long double wheel_z = -(l/2.0)*cos(rotate_rad) + (l/2.0);

        complex<long double> xy(x, y-wheel_y);
        // complexのnormは2乗されたものが返される
        // ユークリッドノルムにするためにはsqrtが必要
        long double xy_dist = sqrt(norm(xy));

        long double res_rad = atan(wheel_z/xy_dist);
        cout << setprecision(8) << 180.0*res_rad/PI << endl;
    }
}