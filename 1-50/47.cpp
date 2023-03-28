#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

bool hasFourDistinctPrimeFactors(ll n) {
    vector<pii> factorisation;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            } factorisation.push_back({n, i});
        }
    } 

    if (n > 1) {
        factorisation.push_back({n, 1});
    }

    return int(factorisation.size()) == 4;
}

void solve() {
    bool notFound = true;
    int k = 2;
    while (notFound) {
        if (hasFourDistinctPrimeFactors(k) && hasFourDistinctPrimeFactors(k + 1) && hasFourDistinctPrimeFactors(k + 2) && hasFourDistinctPrimeFactors(k + 3)) {
            cout << k << "\n";
            notFound = false;
        } k++;
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