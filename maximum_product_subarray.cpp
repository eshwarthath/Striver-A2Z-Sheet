class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        
        int prefix_sum = 1;
        int sufix_sum = 1;
        int maxi = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            
            if(prefix_sum == 0)
                prefix_sum = 1;
            if(sufix_sum == 0)
                sufix_sum = 1;
            
            prefix_sum = prefix_sum*nums[i];
            sufix_sum = sufix_sum*nums[n-i-1];
            
            maxi = max(maxi, max(prefix_sum,sufix_sum));
        }
        
        return maxi;
    }
};
