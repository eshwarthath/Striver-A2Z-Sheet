class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num, target, 0, 0, 0, "", ans);
        return ans;
    }

    void solve(string &num, long long target, int i,
               long long val, long long prev,
               string path, vector<string> &ans) {
        if (i == num.size()) {
            if (val == target) ans.push_back(path);
            return;
        }

        for (int j = i; j < num.size(); j++) {
            if (j > i && num[i] == '0') break;

            string s = num.substr(i, j - i + 1);
            long long n = stoll(s);

            if (i == 0) {
                solve(num, target, j + 1, n, n, s, ans);
            } else {
                solve(num, target, j + 1, val + n, n,
                      path + "+" + s, ans);

                solve(num, target, j + 1, val - n, -n,
                      path + "-" + s, ans);

                solve(num, target, j + 1,
                      val - prev + prev * n, prev * n,
                      path + "*" + s, ans);
            }
        }
    }
};
