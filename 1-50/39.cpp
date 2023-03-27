#include <bits/stdc++.h>
using namespace std;

using ll = long long;

map<int, set<int>> mp;
 
void solve() {
    int bound = floor(sqrt(1000/2));
    for (int v = 1; v <= bound; v++) {
        for (int u = v + 1; u <= bound; u++) {
            int p = 2 * u * (u + v);
            for (int q = p; q <= 1000; q += p) {
                mp[q].insert((u * u + v * v) * (q/p));
            }
        }
    }

    int count = 0, p;
    for (int i = 0; i <= 1000; i++) {
        if (count < mp[i].size()) {
            count = mp[i].size();
            p = i;
        }
    } cout << p << "\n"; 
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