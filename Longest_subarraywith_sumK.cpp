class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){

        map<long long, int> preSumMin;
        long long sum = 0;
        int maxlen = 0;

        for(int i = 0; i < nums.size(); i++){

            sum += nums[i];

            if(sum == k)
                maxlen = max(maxlen, i + 1);

            long long rem = sum - k;

            if(preSumMin.find(rem) != preSumMin.end())
                maxlen = max(maxlen, i - preSumMin[rem]);

            if(preSumMin.find(sum) == preSumMin.end())
                preSumMin[sum] = i;
        }

        return maxlen;
    }
};
