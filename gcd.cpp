#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int GCD(int n1, int n2) {
        vector<int> divisors_n1;
        vector<int> divisors_n2;

        // divisors of n1
        for (int i = 1; i <= n1; i++) {
            if (n1 % i == 0) {
                divisors_n1.push_back(i);
            }
        }

        // divisors of n2
        for (int i = 1; i <= n2; i++) {
            if (n2 % i == 0) {
                divisors_n2.push_back(i);
            }
        }

        int gcd = 1;

        // find greatest common divisor
        for (int i = 0; i < divisors_n1.size(); i++) {
            for (int j = 0; j < divisors_n2.size(); j++) {
                if (divisors_n1[i] == divisors_n2[j]) {
                    gcd = divisors_n1[i];  // keeps updating to larger value
                }
            }
        }

        return gcd;
    }
};

int main() {
    Solution s;
    int n1, n2;
    cin >> n1 >> n2;

    cout << s.GCD(n1, n2);
    return 0;
}
