// https://atcoder.jp/contests/typical90/tasks/typical90_bo

#include <bits/stdc++.h>
using namespace std;

// 基数変換を知る
long long base8_to_long (string N) {
	long long res = 0;
	for (int i = 0; i < N.size(); i++) res = res * 8 + int(N[i] - '0');
	return res;
}
string long_to_base9 (long long N) {
	if (N == 0) {
		return "0";
	}
	string res;
	while (N > 0) {
		res = char(N % 9 + '0') + res;
		N /= 9;
	}
	return res;
}

int main () {
    string n;
    int k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        n = long_to_base9(base8_to_long(n));
        for (int j = 0; j < n.size(); j++) {
            if (n[j] == '8') n[j] = '5';
        }
    }
    cout << n << endl;
    
}