// https://atcoder.jp/contests/abc202/tasks/abc202_d

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    long long k;
    cin >> a >> b >> k;
    
    // 組合せの数を事前に計算
    // 桁あふれを防ぐためlong longにしておく
    long long n = a + b;
    vector<vector<long long>> comb(n+1, vector<long long>(n+1, 0));
    for (int i = 0; i <= n; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]);
        }
    }

    // 先頭から文字を決めていく, 後ろの並びの数は組合せで表せる
    for (int i = 0; i < n; i++) {
        if (a == 0) cout << 'b';
        else if (b == 0) cout << 'a';
        else if (comb[a+b-1][a-1] >= k) {
            cout << 'a';
            a--;
        } else {
            cout << 'b';
            k -= comb[a+b-1][a-1];
            b--;
        }
    }

    cout << endl;
}