#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[1001010];

ll collatz(ll i) {
    if (i == 1) {
        return 1;
    }

    if (i < 1000000 && dp[i] != 0) {
        return dp[i];
    }

    ll ans = 0;
    if (i % 2 == 0) {
        ans = 1 + collatz(i/2);
    } else {
        ans = 1 + collatz(3 * i + 1);
    }

    if (i < 1000000) {
        return dp[i] = ans;
    } return ans;
}

void solve() {    

    memset(dp, 0, sizeof(dp));

    ll longestLen = 1, ans = 1;
    for (ll i = 1; i < 1000000; i++) {
        if (collatz(i) > longestLen) {
            longestLen = collatz(i);
            ans = i;
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
