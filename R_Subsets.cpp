class Solution {
public:
    void generate(int index, vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans) {

        // Base case
        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Include the current element
        curr.push_back(nums[index]);
        generate(index + 1, nums, curr, ans);

        // Backtrack
        curr.pop_back();

        // Exclude the current element
        generate(index + 1, nums, curr, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        generate(0, nums, curr, ans);

        return ans;
    }
};
