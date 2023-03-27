#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 50000000;
bool inSet[50505050];

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

vector<int> prime_powers(int n, int k) {
    int bound = floor(pow(n, 1.00/k));
    vector<bool> is_prime = sieve(bound);
    vector<int> primes;
    for (int i = 0; i <= bound; i++) {
        if (is_prime[i]) {
            primes.push_back(pow(i, k));
        }
    } return primes;
}

void solve() {
    vector<int> squares = prime_powers(N, 2);
    vector<int> cubes = prime_powers(N, 3);
    vector<int> fourth_powers = prime_powers(N, 4);
    memset(inSet, false, sizeof(inSet));
    int count = 0;
    for (int x : squares) {
        for (int y : cubes) {
            for (int z : fourth_powers) {
                if (x + y + z < N) {
                    if (!inSet[x + y + z]) {
                        inSet[x + y + z] = true;
                        count++;
                    }
                } else {
                    break; 
                }
            }
        }
    } cout << count << "\n";
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