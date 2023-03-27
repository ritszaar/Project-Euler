#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 10000000;

bool isTruncPrime(int n, const vector<bool>& is_prime) {
    int nDigits = floor(log10(n)) + 1;
    int k = n;
    while (k > 0) {
        if (!is_prime[k]) {
            return false;
        }

        k = k % int(pow(10, floor(log10(k))));
    } 

    k = n;
    while (k > 0) {
        if (!is_prime[k]) {
            return false;
        }

        k = k/10;
    } return true;
}

vector<bool> sieve(int n) {
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
    vector<bool> is_prime = sieve(N);
    ll sum = 0;
    int count = 0;
    for (int i = 11; i <= N && count < 11; i++) {
        if (isTruncPrime(i, is_prime)) {
            sum += i;
            count++;
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