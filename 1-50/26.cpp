#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string recurringPart(int numr, int denr) {
    string res;
    map<int, int> mp;
    mp.clear();
 
    int rem = numr % denr;
 
    while ((rem != 0) && (mp.find(rem) == mp.end())) {
        mp[rem] = res.length(); 
        rem = rem * 10;
 
        int res_part = rem / denr;
        res += to_string(res_part);
 
        rem = rem % denr;
    }
 
    return (rem == 0) ? "" : res.substr(mp[rem]);
}

void solve() {
    int len = 0, d = 0;
    for (int i = 1; i <= 1000; i++) {
        int thisLen = int(recurringPart(1, i).length());
        if (len < thisLen) {
            len = thisLen;
            d = i;
        }
    } cout << d << "\n";
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