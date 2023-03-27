#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;

void solve() {
    n = 4000000;
    int u = 1, v = 2;
    ll sum = 0;
    while (v <= n) {
        if (v % 2 == 0) {
            sum += 1LL * v;
        }

        int temp = u;
        u = v;
        v += temp;
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