#include <bits/stdc++.h>
using namespace std;

const int n = 20;

int arr[n][n];

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void solve() {
    ifstream fin("11.txt");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> arr[i][j];
        }
    } fin.close();

    int w = 4;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Row
            int product = 1;
            for (int k = j; k < j + w; k++) {
                if (!isValid(i, k)) {
                    product = 0;
                    break;
                } else {
                    product *= arr[i][k];
                }
            } ans = max(ans, product);

            // Column
            product = 1;
            for (int k = i; k < i + w; k++) {
                if (!isValid(k, j)) {
                    product = 0;
                    break;
                } else {
                    product *= arr[k][j];
                }
            } ans = max(ans, product);

            // One Diagonal
            product = 1;
            for (int k = 0; k < w; k++) {
                if (!isValid(i + k, j + k)) {
                    product = 0;
                    break;
                } else {
                    product *= arr[i + k][j + k];
                }
            } ans = max(ans, product);

            // Other Diagonal
            product = 1;
            for (int k = 0; k < w; k++) {
                if (!isValid(i + k, j - k)) {
                    product = 0;
                    break;
                } else {
                    product *= arr[i + k][j - k];
                }
            } ans = max(ans, product);
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