class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        function<void(int, int)> backtrack = [&](int start, int sum) {
            if (temp.size() == k) {
                if (sum == n) {
                    ans.push_back(temp);
                }
                return;
            }

            for (int i = start; i <= 9; i++) {
                if (sum + i > n)
                    break;

                temp.push_back(i);
                backtrack(i + 1, sum + i);
                temp.pop_back();
            }
        };

        backtrack(1, 0);

        return ans;
    }
};
