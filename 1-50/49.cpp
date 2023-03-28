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

bool arePermutations(int x, int y, int z) {
    map<int, int> mx, my, mz;
    while (x > 0 && y > 0 && z > 0) {
        mx[x % 10]++;
        my[y % 10]++;
        mz[z % 10]++;
        x /= 10, y /= 10, z /= 10;
    }

    if (x != 0 || y != 0 || z != 0) {
        return false;
    }
    
    for (int i = 0; i < 10; i++) {
        if (!(mx[i] == my[i] && my[i] == mz[i])) {
            return false;
        }
    } return true;
}

void solve() {
    vector<bool> is_prime = sieve(N);
    for (int i = 1000; i <= 9999; i++) {
        if (!is_prime[i] || i == 1487) continue;
        for (int j = i + 1; j <= 9999; j++) {
            if (!is_prime[j]) continue;
            int k = j + (j - i);
            if (is_prime[k]) {
                if (arePermutations(i, j, k)) {
                    string ans = to_string(i) + to_string(j) + to_string(k);
                    cout << ans << "\n";
                    return;
                }
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