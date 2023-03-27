#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

#define F first
#define S second

ll divisorCount(ll x) {
    ll ans = 1;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                cnt++;
                x /= i;
            } ans *= (cnt + 1);
        }
    }

    if (x > 1) {
        ans *= 2;
    } return ans;
}

void solve() {
    ll n = 1, k = 1;
    while (divisorCount(n) <= 500) {
        k++;
        n += k;
    } cout << n << "\n";
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