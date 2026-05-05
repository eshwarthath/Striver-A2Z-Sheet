class Solution {
public:
    int MOD = 10000003;

    bool canPaint(vector<int> &C, int A, long long maxLen) {
        long long curr = 0;
        int painters = 1;

        for (int i = 0; i < C.size(); i++) {
            if (C[i] > maxLen) return false;

            if (curr + C[i] <= maxLen) {
                curr += C[i];
            } else {
                painters++;
                curr = C[i];
            }
        }

        return painters <= A;
    }

    int paint(int A, int B, vector<int>& C) {
        long long low = 0, high = 0;

        for (int x : C) {
            low = max(low, (long long)x); // minimum possible
            high += x;                   // maximum possible
        }

        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (canPaint(C, A, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (ans % MOD * B % MOD) % MOD;
    }
};
