#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1000000;

void solve() {
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < N - 1; i++) {
        next_permutation(digits.begin(), digits.end());
    }

    for (int digit : digits) {
        cout << digit;
    } cout << "\n";
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