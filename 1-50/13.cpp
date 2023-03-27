#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<string> nums;
    string num;
    ifstream fin("13.txt");
    while (!fin.eof()) {
        fin >> num;
        nums.push_back(num);
    } fin.close();

    string ans = "";
    int sum = 0;
    for (int i = 49; i >= 0; i--) {
        for (int j = 0; j < int(nums.size()); j++) {
            sum += nums[j][i] - '0';
        }

        ans = char(sum % 10 + '0') + ans;
        sum /= 10;
    }

    if (sum > 0) {
        ans = to_string(sum) + ans;
    } cout << ans.substr(0, 10) << "\n";
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