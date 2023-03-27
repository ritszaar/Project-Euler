#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
ll dp[25][25];

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

ll rec(ll i, ll j) {
    // Base Case
    if (i == n - 1 && j == n - 1) {
        return 1;
    } 

    // Cache Check
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    // Transitions
    ll ans = 0;
    if (isValid(i + 1, j)) {
        ans += rec(i + 1, j);
    } 

    if (isValid(i, j + 1)) {
        ans += rec(i, j + 1);
    }
    

    // Save and Return
    return dp[i][j] = ans;
}

void solve() {    
    n = 21;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << "\n";
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
