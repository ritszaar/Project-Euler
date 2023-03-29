#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 1;

class VarInt {
    public:

        vector<int> digits;

        VarInt() {
            digits = vector<int>(1, 0);
        }

        VarInt(const vector<int>& digits_) {
            for (int i = 0; i < int(digits_.size()); i++) {
                digits.push_back(digits_[i]);
            }
        }

        VarInt(int k) {
            while (k > 0) {
                digits.push_back(k % 10);
                k /= 10;
            }
        }

        VarInt(ll k) {
            while (k > 0) {
                digits.push_back(k % 10);
                k /= 10;
            }
        }

        VarInt(string k) {
            for (int i = int(k.length()) - 1; i >= 0; i--) {
                digits.push_back(int(k[i] - '0'));
            } 
        }

        VarInt operator+(const VarInt& v) const {
            vector<int> sumDigits;
            int commonLen = min(digits.size(), v.digits.size());
            int sum = 0;
            for (int i = 0; i < commonLen; i++) {
                sum += v.digits[i] + digits[i];
                sumDigits.push_back(sum % 10);
                sum /= 10;
            }

            if (digits.size() < v.digits.size()) {
                for (int i = commonLen; i < int(v.digits.size()); i++) {
                    sum += v.digits[i];
                    sumDigits.push_back(sum % 10);
                    sum /= 10;
                }
            }

            if (v.digits.size() < digits.size()) {
                for (int i = commonLen; i < int(digits.size()); i++) {
                    sum += digits[i];
                    sumDigits.push_back(sum % 10);
                    sum /= 10;
                }
            }

            while (sum > 0) {
                sumDigits.push_back(sum % 10);
                sum /= 10;
            }
            
            return VarInt(sumDigits);
        }

        bool operator==(const VarInt& v) const {
            if (digits.size() != v.digits.size()) {
                return false;
            }

            for (int i = 0; i < int(digits.size()); i++) {
                if (digits[i] != v.digits[i]) {
                    return false;
                }
            } return true;
        }

        VarInt operator*(const VarInt& v) const {
            vector<VarInt> partialProducts;
            for (int i = 0; i < int(v.digits.size()); i++) {
                int product = 0;
                vector<int> productDigits;
                for (int k = 0; k < i; k++) {
                    productDigits.push_back(0);
                }
                for (int j = 0; j < int(digits.size()); j++) {
                    product += v.digits[i] * digits[j];
                    productDigits.push_back(product % 10);
                    product /= 10;
                }

                while (product > 0) {
                    productDigits.push_back(product % 10);
                    product /= 10;
                } 

                partialProducts.push_back(VarInt(productDigits));
            }

            VarInt res = 0;
            for (const VarInt& partialProduct : partialProducts) {
                res = res + partialProduct;
            } return res;
        }

        static VarInt pow(VarInt v, int k) {
            VarInt res = 1;
            for (int i = 0; i < k; i++) {
                res = res * v;
            } return res;
        }

        int digitSum() {
            int sum = 0;
            for (int i = 0; i < int(digits.size()); i++) {
                sum += digits[i];
            } return sum;
        }

        friend ostream& operator<<(ostream& os, const VarInt& v) {
            for (int i = int(v.digits.size()) - 1; i >= 0; i--) {
                cout << v.digits[i];
            } return os;
        }
};

VarInt ncr[128][128];

void solve() {
    int n = 101, count = 0;
    ncr[0][0] = 1;
    for (int i = 1; i < n; i++) {
        ncr[i][0] = 1;
        for (int j = 1; j < n; j++) {
            ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
            if (ncr[i][j].digits.size() >= 7 && !(ncr[i][j] == 1000000)) {
                count++;
            }
        }
    }  cout << count << "\n";  
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