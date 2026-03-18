#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());  // Step 1: Sort the array
        
        for(int i = 0; i < n - 2; i++) {
            
            // Skip duplicate elements for i
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int j = i + 1;
            int k = n - 1;
            
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum < 0) {
                    j++;   // Need bigger sum
                }
                else if(sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    
                    j++;
                    k--;
                    
                    // Skip duplicates for left
                    while(j < k && nums[j] == nums[j - 1])
                        j++;
                    
                    // Skip duplicates for right
                    while(j < k && nums[k] == nums[k + 1])
                        k--;
                }
                else {
                    k--;  // if (sum > 0)
                }
            }
        }
        
        return result;
    }
};
