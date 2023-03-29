#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6;

bool isPermutedMultiple(ll n) {
    map<int, int> mp[6];
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        ll k = (i + 1) * n;
        while (k > 0) {
            mp[i][k % 10]++;
            k /= 10;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (mp[i][j] != mp[i + 1][j]) {
                return false;
            }
        } 
    } return true;
}

void solve() {
    for (int i = 1; i < N; i++) {
        if (isPermutedMultiple(i)) {
            cout << i << "\n";
            break;
        }
    }
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