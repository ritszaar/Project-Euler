#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    int nDigits = 0;
    for (int i = 1; nDigits < 1001010; i++, nDigits += floor(log10(i)) + 1) {
        s += to_string(i);
    }   

    int product = 1;
    for (int i = 10; i <= 1000000; i *= 10) {
        product *= s[i - 1] - '0';
    } cout << product << "\n";
}

inline void debugMode() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    debugMode();

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}