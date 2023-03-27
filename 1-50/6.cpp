#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;

void solve() {
    n = 100;
    ll ans = pow((n * (n + 1)/2), 2) - n * (n + 1) * (2 * n + 1)/6;
    cout << ans << "\n";
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