class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = nums.size();
        int floorVal = -1;
        int ceilVal = -1;

        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == x) {
                // exact match → both floor and ceil
                return {nums[mid], nums[mid]};
            }
            else if (nums[mid] < x) {
                floorVal = nums[mid];  // possible floor
                low = mid + 1;
            }
            else {
                ceilVal = nums[mid];   // possible ceil
                high = mid - 1;
            }
        }

        return {floorVal, ceilVal};
    }
};
