#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define F first
#define S second

set<pii> prime_factorise(int a, int b) {
    set<pii> factorisation;
    for (int i = 2; i * i <= a; i++) {
        int cnt = 0;
        if (a % i == 0) {
            while (a % i == 0) {
                a /= i;
                cnt++;
            } factorisation.insert({i, cnt * b});
        }
    } 

    if (a > 1) {
        factorisation.insert({a, 1 * b});
    } return factorisation;
}

void solve() {
    set<set<pii>> factorisations;
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            factorisations.insert(prime_factorise(a, b));
        }
    }

    cout << factorisations.size() << "\n";
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