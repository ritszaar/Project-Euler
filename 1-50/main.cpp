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
    vector<int> primes;
    for (int i = 0; i <= N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    int prime, maxLen = 0;
    for (int i = 0; i < int(primes.size()); i++) {
        int sum = primes[i], len = 1;
        int validSum = sum, validLen = len;
        for (int j = i + 1; j < int(primes.size()); j++) {
            if (sum + primes[j] < N) {
                sum += primes[j];
                len++;
                if (is_prime[sum]) {
                    validSum = sum;
                    validLen = len;
                }
            } else {
                break;
            }
        }

        if (maxLen < validLen) {
            maxLen = validLen;
            prime = validSum;
        }
    } cout << prime << "\n";
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