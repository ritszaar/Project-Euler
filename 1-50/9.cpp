#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    n = 1000;
    for (int v = 1; v * v <= n; v++) {
        for (int u = v + 1; u * u <= n; u++) {
            int c = u * u + v * v;
            int b = 2 * u * v;
            int a = u * u - v * v;
            if (a + b + c == n) {
                cout << a * b * c << "\n";
            }
        }
    }
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