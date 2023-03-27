#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define int ll

vector<bool> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        for (ll j = 1LL * i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    } return is_prime;
}

void solve() {
    vector<bool> is_prime = sieve(10000000LL);

    int maxN = 0, product;
    for (int a = -999; a <= 999; a++) {
        for (int b = -1000; b <= 1000; b++) {
            int n = 0;
            bool valid = true;
            while (valid) {
                int y = n * n + a * n + b;
                if (y < 2 || !is_prime[y]) {
                    valid = false;
                } else {
                    n++;
                }
            }

            if (maxN < n) {
                maxN = n;
                product = a * b;
            }
        }
    } cout << product << "\n";
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