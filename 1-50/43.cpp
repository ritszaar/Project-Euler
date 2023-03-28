#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll fact[12];

ll getNum(const vector<int>& digits) {
    ll num = 0;
    ll place = 1;
    for (int i = int(digits.size()) - 1; i >= 0; i--, place *= 10) {
        num += digits[i] * place;
    } return num;
}

void solve() {
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17};
    fact[0] = 1;
    for (int i = 1; i <= 10; i++) {
        fact[i] = i * fact[i - 1];
    }

    ll sum = 0;
    for (int i = 0; i < fact[10]; i++, next_permutation(digits.begin(), digits.end())) {
        int isSubstringDivisible = true;
        for (int j = 1; j < int(digits.size()) - 2; j++) {
            int num = digits[j] * 100 + digits[j + 1] * 10 + digits[j + 2];
            if (num % primes[j - 1] != 0) {
                isSubstringDivisible = false;
                break;
            } 
        }

        if (isSubstringDivisible) {
            sum += getNum(digits);
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