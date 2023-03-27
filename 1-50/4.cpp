#include <bits/stdc++.h>
using namespace std;

bool isPalidrome(int n) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }

    for (int i = 0, j = int(digits.size()) - 1; i <= j; i++, j--) {
        if (digits[i] != digits[j]) return false;
    } return true;
}

void solve() {
    int ans = 0;
    for (int a = 999; a >= 100; a--) {
        for (int b = a - 1; b >= 100; b--) {
            if (isPalidrome(a * b)) {
                ans = max(ans, a * b);
            }
        }
    } cout << ans << "\n";
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