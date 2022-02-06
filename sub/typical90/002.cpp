// https://atcoder.jp/contests/typical90/tasks/typical90_b

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    if (n % 2 == 1) {
        return 0;
    }

    // '('と')'が同じ数
    // すべてのiについて, 左からi文字目までの時点で'('の数が')'の数以上である
    string s = string(n/2, '(') + string(n/2, ')');
    do {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count += 1;
            } else {
                count -= 1;
            }

            if (count < 0) break;
        }

        if (count == 0) cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}