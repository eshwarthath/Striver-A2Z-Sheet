class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        long long currentSum = 0;
        int parts = 1;

        for (int num : nums) {
            if (currentSum + num > maxSum) {
                parts++;
                currentSum = num;

                if (parts > k) return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long long left = *max_element(nums.begin(), nums.end());
        long long right = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = right;

        while (left <= right) {
            long long mid = (left + right) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return (int)ans;
    }
};
