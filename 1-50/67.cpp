#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<vector<int>> triangle;
ll dp[110][110];

ll rec(int row, int col) {
    // Base Case
    if (row == n - 1) {
        return triangle[row][col];
    }

    // Cache Check
    if (dp[row][col] != -1) {
        return dp[row][col];
    }

    // Transitions
    ll ans = 0LL;
    ans = max(ans, 1LL * triangle[row][col] + rec(row + 1, col)); 
    ans = max(ans, 1LL * triangle[row][col] + rec(row + 1, col + 1));

    // Save and Return
    return dp[row][col] = ans;
}

void solve() {
    ifstream fin("67.txt");
    int num;
    for (int i = 0; !fin.eof(); i++) {
        triangle.push_back(vector<int>());
        for (int j = 0; j <= i; j++) {
            fin >> num;
            triangle[i].push_back(num);
        }
    } fin.close();

    n = triangle.size();

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