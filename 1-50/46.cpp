#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6;

vector<bool> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        for (ll j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    } return is_prime;
}

void solve() {
    vector<bool> is_prime = sieve(N);
    for (int i = 3; ; i += 2) {
        if (!is_prime[i]) {
            bool canBeDone = false;
            for (int j = 2; j < i; j++) {
                if (is_prime[j]) {
                    if (floor(sqrt((i - j)/2)) == sqrt((i - j)/2)) {
                        canBeDone = true;
                        break;
                    } 
                }
            }

            if (!canBeDone) {
                cout << i << "\n";
                break;
            }
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