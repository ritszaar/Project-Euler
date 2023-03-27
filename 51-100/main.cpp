#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool compareFrac(int u, int v, int a, int b) {
    int uvgcd = __gcd(u, v);
    int abgcd = __gcd(a, b);
    u /= uvgcd;
    v /= uvgcd;
    a /= abgcd;
    b /= abgcd;
    return u == a && v == b;
}

bool isDigitCancellingFraction(int a, int b) {
    int aones = a % 10, ahuns = a/10;
    int bones = b % 10, bhuns = b/10;
    int flag = false;
    if (aones == bones && aones != 0) {
        if (compareFrac(ahuns, bhuns, a, b)) flag = true;
    } else if (aones == bhuns && aones != 0) {
        if (compareFrac(ahuns, bones, a, b)) flag = true;
    } else if (ahuns == bones &&  ahuns != 0) {
        if (compareFrac(aones, bhuns, a, b)) flag = true;
    } else if (ahuns == bhuns && ahuns != 0) {
        if (compareFrac(aones, bones, a, b)) flag = true;
    } return flag;
}

void solve() {
    int num = 1, den = 1;
    for (int a = 10; a <= 99; a++) {
        for (int b = a + 1; b <= 99; b++) {
            if (isDigitCancellingFraction(a, b)) {
               num *= a, den *= b; 
            }
        }
    }
    
    den /= __gcd(num,den);
    cout << den << "\n";
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