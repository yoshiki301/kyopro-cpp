// https://atcoder.jp/contests/typical90/tasks/typical90_aa

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    
    // mapでも可
    set<string> signed_up;
    for (int i = 0; i < n; i++) {
        auto it = signed_up.find(s[i]);
        if (it == signed_up.end()) {
            signed_up.insert(s[i]);
            cout << i + 1 << endl;
        }
    }
}