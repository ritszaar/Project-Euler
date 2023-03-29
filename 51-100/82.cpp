#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
int grid[128][128];
ll dp[128][128][3];

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

ll rec(int row, int col, int move) {
    // Base Case
    if (!isValid(row, col)) {
        return INT64_MAX;
    }

    if (col == n - 1) {
        return grid[row][col];
    }

    // Cache Check
    if (dp[row][col][move] != -1) {
        return dp[row][col][move];
    }

    // Transitions
    ll ans = INT64_MAX;
    if (move == 1) {
        ans = min(rec(row - 1, col, 1), rec(row, col + 1, 0));
    } else if (move == 2) {
        ans = min(rec(row + 1, col, 2), rec(row, col + 1, 0));
    } else {
        ans = min(rec(row + 1, col, 2), min(rec(row - 1, col, 1), rec(row, col + 1, 0)));
    }

    ans += grid[row][col];

    // Save and return
    return dp[row][col][move] = ans;
}

void solve() {
    n = 80;
    ifstream fin("82.txt");
    string row, col;
    for (int i = 0; i < n; i++) {
        fin >> row;
        stringstream rowin(row);
        for (int j = 0; j < n; j++) {
            getline(rowin, col, ',');
            grid[i][j] = stoi(col);
        }
    }

    ll ans = INT64_MAX;
    for (int i = 0; i < n; i++) {
        memset(dp, -1, sizeof(dp));
        ans = min(ans, rec(i, 0, 0));
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