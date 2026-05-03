class Solution {
public:
    
    bool canAllocate(vector<int>& nums, int m, int maxPages) {
        int students = 1;
        int pages = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxPages) return false;

            if (pages + nums[i] <= maxPages) {
                pages += nums[i];
            } else {
                students++;
                pages = nums[i];

                if (students > m) return false;
            }
        }
        return true;
    }

    int findPages(vector<int> &nums, int m) {
        int n = nums.size();
        if (m > n) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canAllocate(nums, m, mid)) {
                ans = mid;
                high = mid - 1;   // try smaller max
            } else {
                low = mid + 1;    // increase max
            }
        }

        return ans;
    }
};
