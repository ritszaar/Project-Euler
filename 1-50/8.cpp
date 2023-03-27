#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 10000;

void solve() {
    string num = "", partnum;
    ifstream fin("8.txt");
    while (!fin.eof()) {
        fin >> partnum;
        num += partnum;
    } fin.close();

    int k = 13;
    ll ans = 0;
    for (int i = 0; i < int(num.size()) - k; i++) {
        ll product = 1;
        for (int j = i; j < i + k; j++) {
            product *= num[j] - '0';
        } ans = max(ans, product);
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