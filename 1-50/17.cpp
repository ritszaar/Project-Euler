#include <bits/stdc++.h>
using namespace std;

const int N = 50000000;

using ll = long long;

string word[1010];

string numberToWord(int n) {
    if (n < 20 || n == 1000) {
        return word[n];
    }

    int tens = n % 100;
    string suffix;
    if (tens < 20) {
        suffix = word[tens];
    } else {
        if (tens % 10 == 0) {
            suffix = word[tens];
        } else {
            suffix = word[tens - (tens % 10)] + "-" + word[tens % 10];
        }
    }

    if (n >= 100) {
        if (n % 100 == 0) {
            return word[n/100] + " hundred";
        } else {
            return word[n/100] + " hundred and " + suffix;
        }
    } return suffix;
}

int countAlphabets(string word) {
    int count = 0;
    for (char c : word) {
        if (isalpha(c)) count++;
    } return count;
}

void solve() {
    word[1]  = "one";
    word[2]  = "two";
    word[3]  = "three";
    word[4]  = "four";
    word[5]  = "five";
    word[6]  = "six";
    word[7]  = "seven";
    word[8]  = "eight";
    word[9]  = "nine";
    word[10] = "ten";
    word[11] = "eleven";
    word[12] = "twelve";
    word[13] = "thirteen";
    word[14] = "fourteen";
    word[15] = "fifteen";
    word[16] = "sixteen";
    word[17] = "seventeen";
    word[18] = "eighteen";
    word[19] = "nineteen";
    word[20] = "twenty";
    word[30] = "thirty";
    word[40] = "forty";
    word[50] = "fifty";
    word[60] = "sixty";
    word[70] = "seventy";
    word[80] = "eighty";
    word[90] = "ninety";
    word[1000] = "one thousand";
    int count = 0;
    for (int i = 1; i <= 1000; i++) {
        count += countAlphabets(numberToWord(i));
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