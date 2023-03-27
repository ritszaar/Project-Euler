#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;

void solve() {
    n = 20;
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ll gcd = __gcd<ll>(ans, i); 
        ans = (ans / gcd) * i;
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