class Solution {
public:
    void generate(int index, vector<int>& candidates, int target,int sum, vector<int>& curr,
                  vector<vector<int>>& ans) {

        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        if (sum > target || index == candidates.size()) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (sum + candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            generate(i + 1, candidates, target,sum + candidates[i], curr, ans);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        generate(0, candidates, target, 0, curr, ans);

        return ans;
    }
};
