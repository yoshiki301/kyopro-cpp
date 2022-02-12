// 

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> t(q), x(q), y(q);
    for(int i = 0; i < q; i++) cin >> t[i] >> x[i] >> y[i];

    // 何回シフトしたか記録
    // T=2のクエリでshift -= 1 (mod n)とする
    int shift = 0;
    for (int i = 0; i < q; i++) {
        if (t[i] == 1) {
            int x_mod = (x[i]-1 + shift) % n;
            int y_mod = (y[i]-1 + shift) % n;
            swap(a[x_mod], a[y_mod]);
        } else if (t[i] == 2) {
            shift = (shift + n - 1) % n;
        } else {
            int x_mod = (x[i]-1 + shift) % n;
            cout << a[x_mod] << endl;
        }
    }
}