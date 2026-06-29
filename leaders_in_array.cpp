class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();    
        int largest = nums[n-1];
        ans.push_back(largest);
        for(int i =n-2; i>=0; i--){
            if(nums[i]> largest){
                    ans.push_back(nums[i]);
                    largest = max(largest,nums[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
