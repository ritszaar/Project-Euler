#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1000000;

int digitalFifthPower(int n) {
    int ans = 0;
    while (n > 0) {
        ans += pow(n % 10, 5);
        n /= 10;
    } return ans;
}

void solve() {
    ll sum = 0;
    for (int i = 2; i < N; i++) {
        if (digitalFifthPower(i) == i) {
            sum += 1LL * i;
        }
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