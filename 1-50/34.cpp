#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100000000;

ll factorials[12];

int digitalFactorial(int x) {
    int ans = 0;
    while (x > 0) {
        ans += factorials[x % 10];
        x /= 10;
    } return ans;
}

void solve() {
    factorials[0] = 1;
    for (int i = 1; i <= 9; i++) {
        factorials[i] = i * factorials[i - 1];
    }

    int sum = 0;
    for (int i = 3; i < N; i++) {
        if (digitalFactorial(i) == i) {
            sum += i;
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