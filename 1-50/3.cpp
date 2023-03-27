#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;

void solve() {
    n = 600851475143;
    ll k = n, ans = 0;
    for (ll i = 2; i * i <= n; i++) {
        if (k % i == 0) {
            ans = i;
            while (k % i == 0) {
                k /= i;
            }
        }
    }

    ans = k > ans ? k : ans;
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