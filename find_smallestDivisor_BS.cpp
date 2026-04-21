class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;

            long long sum = 0;
            for (int x : nums) {
                sum += (x + mid - 1) / mid;  // ceil division
            }

            if (sum <= threshold) {
                ans = mid;
                high = mid - 1;  // try smaller divisor
            } else {
                low = mid + 1;   // increase divisor
            }
        }

        return ans;
    }
};
