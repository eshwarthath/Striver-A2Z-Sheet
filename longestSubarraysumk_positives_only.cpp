class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int left = 0;
        int right = 0;
        int maxlen = 0;
        long long sum = nums[0];
        while(right< nums.size()){
            if(left<=right && sum> k){
                sum -= nums[left];
                left++;
            }
            right++;
            if (right< nums.size()) sum+= nums[right];
            
            if(sum == k){
                 maxlen = max(maxlen, right-left +1);
            }
            
        }
        return maxlen;

    }
};
