// https://atcoder.jp/contests/abc202/tasks/abc202_b

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    // 難しい内容ではないが, vectorの反転と範囲for文の練習
    string rev_s(s.rbegin(), s.rend());
    for (const auto& e: rev_s) {
        if (e == '6') {
            cout << '9';
        } else if (e == '9') {
            cout << '6';
        } else {
            cout << e;
        }
    }
    cout << endl;
}