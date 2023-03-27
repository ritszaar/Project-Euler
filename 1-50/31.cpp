#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
int arr[128];
ll dp[256][10];

ll rec(int x, int level) {
    // Base Case
    if (level == n) {
        if (x == 0) {
            return 1;
        } return 0;
    } 

    // Cache Check  
    if (dp[x][level] != -1) {
        return dp[x][level];
    }


    // Transitions
    ll ans = 0;
    for (int j = 0; j * arr[level] <= x; j++) {
        ans += rec(x - j * arr[level], level + 1);
    }

    // Save and Return
    return dp[x][level] = ans;
}

void solve() {
    n = 8;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 5;
    arr[3] = 10;
    arr[4] = 20;
    arr[5] = 50;
    arr[6] = 100;
    arr[7] = 200;

    memset(dp, -1, sizeof(dp));
    cout << rec(200, 0) << "\n";
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