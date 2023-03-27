#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<vector<int>> triangle;

void rec(int level, int index, int sum, int& maxSum) {
    if (level == n) {
        maxSum = max(sum, maxSum);
        return;
    }

    rec(level + 1, index, sum + triangle[level][index], maxSum);
    rec(level + 1, index + 1, sum + triangle[level][index + 1], maxSum);
}

void solve() {
    ifstream fin("18.txt");
    int num;
    for (int i = 0; !fin.eof(); i++) {
        triangle.push_back(vector<int>());
        for (int j = 0; j <= i; j++) {
            fin >> num;
            triangle[i].push_back(num);
        }
    } fin.close();

    n = triangle.size();

    int maxSum = 0;
    rec(0, 0, 0, maxSum);
    cout << maxSum << "\n";
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