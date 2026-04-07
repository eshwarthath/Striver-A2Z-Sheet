class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& path, vector<bool>& used) {
        
        // Base case: if permutation is complete
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        // Try all choices
        for (int i = 0; i < nums.size(); i++) {

            // Skip if already used
            if (used[i]) continue;

            // Choose
            path.push_back(nums[i]);
            used[i] = true;

            // Explore
            solve(nums, path, used);

            // Backtrack (undo)
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<bool> used(nums.size(), false);

        solve(nums, path, used);
        return ans;
    }
};
