#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = 1LL * i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    } return is_prime;
}

void solve() {
    n = 10001;
    int count = 0;
    vector<bool> is_prime = sieve(1000000);
    for (ll i = 0; i < ll(is_prime.size()); i++) {
        if (is_prime[i]) count++;
        if (count == n) {
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