class Solution {
public:
    int distinctSubseqII(string s) {

        const int MOD = 1000000007;

        vector<long long> last(26, 0);

        long long dp = 1;   // empty subsequence

        for (char ch : s) {

            long long newDp = (2LL * dp - last[ch - 'a']) % MOD;

            if (newDp < 0)
                newDp += MOD;

            last[ch - 'a'] = dp;

            dp = newDp;
        }

        return (dp - 1 + MOD) % MOD;
    }
};
