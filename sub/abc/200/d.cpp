// https://atcoder.jp/contests/abc200/tasks/abc200_d

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long a;
    vector<long> A;
    for (int i = 0; i < n; i++) {
        cin >> a;
        A.push_back(a % 200);
    }

    map<int, int> mod_count;
    for (int i = 0; i < 200; i++) {
        mod_count[i] = 0;
    }

    // 鳩ノ巣原理より, 2^8通り調べれば十分
    // 先頭の最大8要素についてbit全探索を行う
    int bit_n = min(n, 8);
    for (int bit = 1; bit < (1 << bit_n); bit++) {
        int mod_sum = 0;
        for (int i = 0; i < bit_n; i++) {
            if (bit & (1 << i)) {
                mod_sum += A[i];
                mod_sum %= 200;
            }
        }

        if (mod_count[mod_sum] == 0) {
            mod_count[mod_sum] = bit;
        } else {
            cout << "Yes" << endl;
            int b_bit, c_bit;
            b_bit = mod_count[mod_sum];
            c_bit = bit;

            vector<int> B, C;
            for (int i = 0; i < bit_n; i++) {
                if (b_bit & (1 << i)) {
                    B.push_back(i + 1);
                }
                if (c_bit & (1 << i)) {
                    C.push_back(i + 1);
                }
            }

            cout << B.size() << " ";
            for (int i = 0; i < B.size(); i++) {
                cout << B[i] << " ";
            }
            cout << endl;
            cout << C.size() << " ";
            for (int i = 0; i < C.size(); i++) {
                cout << C[i] << " ";
            }
            cout << endl;

            return 0;
        }
    }
    cout << "No" << endl;
}