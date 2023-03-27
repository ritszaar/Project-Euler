#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int partScore(const string& name) {
    int pScore = 0;
    for (const char& c : name) {
        pScore += (c - 'A' + 1);
    } return pScore;
}

void solve() {
    ifstream fin("22.txt");
    vector<string> names;
    string name;
    while (!fin.eof()) {
        getline(fin, name, ',');
        names.push_back(name.substr(1, name.length() - 2));
    } 

    sort(names.begin(), names.end());

    ll score = 0;
    for (int i = 0; i < int(names.size()); i++) {
        score += 1LL * (i + 1) * partScore(names[i]);
    } cout << score << "\n";
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