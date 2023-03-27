#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isPalindromic(int n, int b) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % b);
        n /= b;
    }

    for (int i = 0, j = int(digits.size()) - 1; i <= j; i++, j--) {
        if (digits[i] != digits[j]) {
            return false;
        }
    } return true;
}

void solve() {
    ll sum = 0;
    for (int i = 0; i < 1000000; i++) {
        if (isPalindromic(i, 2) && isPalindromic(i, 10)) {
            sum += i;
        }
    } cout << sum << "\n";
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