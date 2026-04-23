class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;

            int requiredDays = 1;
            int currentLoad = 0;

            for (int w : weights) {
                if (currentLoad + w > mid) {
                    requiredDays++;
                    currentLoad = w;
                } else {
                    currentLoad += w;
                }
            }

            if (requiredDays <= days) {
                ans = mid;
                high = mid - 1; // try smaller capacity
            } else {
                low = mid + 1;  // need bigger capacity
            }
        }

        return ans;
    }
};
