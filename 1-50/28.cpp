#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int spiral[1010][1010];

void solve() {
    int n = 1001;
    int i = n/2, j = n/2;
    int k = 1, len = 2;
    spiral[i][j] = k;
    k++;
    while (k <= n * n) {
        j++;
        for (int ip = i; ip - i + 1 <= len; ip++) {
            spiral[ip][j] = k; 
            k++;
        } i = i + (len - 1);

        j--;
        for (int jp = j; j - jp + 1 <= len; jp--) {
            spiral[i][jp] = k;
            k++;
        } j = j - (len - 1);

        i--;
        for (int ip = i; i - ip + 1 <= len; ip--) {
            spiral[ip][j] = k;
            k++;
        } i = i - (len - 1);

        j++;
        for (int jp = j; jp - j + 1 <= len; jp++) {
            spiral[i][jp] = k;
            k++;
        } j = j + (len - 1);

        len += 2;
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += spiral[i][i] + spiral[i][n - 1 - i];
    } sum -= spiral[n/2][n/2];

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