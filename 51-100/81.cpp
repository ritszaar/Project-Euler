#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
int grid[128][128];
ll dp[128][128];

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

ll rec(int row, int col) {
    // Base Case
    if (!isValid(row, col)) {
        return INT64_MAX;
    }

    if (row == n - 1 &&  col == n - 1) {
        return grid[row][col];
    } 

    // Cache Check
    if (dp[row][col] != -1) {
        return dp[row][col];
    }

    // Transitions
    ll ans = grid[row][col] + min(rec(row + 1, col), rec(row, col + 1));

    // Save and Return
    return dp[row][col] = ans;
}

void solve() {
    n = 80;
    ifstream fin("81.txt");
    string row, col;
    for (int i = 0; i < n; i++) {
        fin >> row;
        stringstream rowin(row);
        for (int j = 0; j < n; j++) {
            getline(rowin, col, ',');
            grid[i][j] = stoi(col);
        }
    }

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