#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int fact[12];

ll getNumber(const vector<int>& digits) {
    ll num = 0;
    ll place = 1;
    for (int i = int(digits.size()) - 1; i >= 0; i--, place *= 10) {
        num += digits[i] * place;
    } return num;
}

bool isPrime(ll num) {
    for (ll i = 2LL; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        } 
    } return true;
}

ll findMaxPanPrime(int n) {
    vector<int> primes;
    vector<int> digits;
    for (int i = 1; i <= n; i++) {
        digits.push_back(i);
    }

    for (int i = 0; i < fact[n]; i++, next_permutation(digits.begin(), digits.end())) {
        ll num = getNumber(digits);
        if (isPrime(num)) {
            primes.push_back(num);
        } 
    } 

    ll maxPrime = -1;
    for (ll prime : primes) {
        maxPrime = max(prime, maxPrime);
    } return maxPrime;
}

bool isProperCode(const string& name) {
    int sum = 0;
    for (char c : name) {
        sum += c - 'A' + 1;
    } return (floor(sqrt(8 * sum + 1)) == sqrt(8 * sum + 1));
}

void solve() {
    ifstream fin("42.txt");
    string name;
    int count = 0;
    while (!fin.eof()) {
        getline(fin, name, ',');
        name = name.substr(1, name.length() - 2);
        if (isProperCode(name)) {
            count++;
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