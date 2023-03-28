#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = 1e10;

ll findRem(ll a, ll b, ll m) {
    ll rem = 1;
    for (ll i = 0; i < b; i++) {
        rem = (rem * a) % m; 
    } return rem;
}

void solve() {
    ll ans = 0;
    for (ll i = 1LL; i <= 1000LL; i++) {
        ans = (ans + findRem(i, i, N)) % N;
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