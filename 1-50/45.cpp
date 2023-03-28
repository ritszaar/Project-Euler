#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

ll fact[12];

ll getNum(const vector<int>& digits) {
    ll num = 0;
    ll place = 1;
    for (int i = int(digits.size()) - 1; i >= 0; i--, place *= 10) {
        num += digits[i] * place;
    } return num;
}

void solve() {
    bool found = false;
    ll ans;
    for (ll i = 144LL; !found; i++) {
        ll h = i  * (2 * i - 1);
        bool isTriangular = floor(sqrt(1 + 8 * h)) == sqrt(1 + 8 * h);
        bool isPentagonal = floor(sqrt(1 + 24 * h)) == sqrt(1 + 24 * h) &&  (int(sqrt(1 + 24 * h)) + 1) % 6 == 0;
        found = isTriangular && isPentagonal && (ans = h);
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