#include <bits/stdc++.h>
using namespace std;

int arr[10100];

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
    int n = 10000;
    for (int i = 1; i < n; i++) {
        arr[i] = divisorSum(i);
    }

    int sum = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i == arr[j] && j == arr[i]) {
                sum += i + j;
            }
        }
    }

    cout << sum << "\n";
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