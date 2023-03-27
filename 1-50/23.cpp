#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int divisorSum(int n) {
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) {
                sum += n/i;
            }
        } 
    } return sum;
}

void solve() {
    vector<int> abundant;
    int n = 28123;
    for (int i = 1; i <= n; i++) {
        if (divisorSum(i) > i) {
            abundant.push_back(i);
        }
    } 

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        bool possible = false;
        for (int x : abundant) {
            int y = i - x;
            if (binary_search(abundant.begin(), abundant.end(), y)) {
                possible = true;
                break;
            }
        }

        if (!possible) {
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