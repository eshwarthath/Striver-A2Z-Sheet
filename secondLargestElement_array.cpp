class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1;

        int largest = nums[0];
        int slargest;
        bool found = false;

        for (int i = 1; i < n; i++) {
            if (nums[i] > largest) {
                slargest = largest;
                largest = nums[i];
                found = true;
            }
            else if (nums[i] < largest) {
                if (!found || nums[i] > slargest) {
                    slargest = nums[i];
                    found = true;
                }
            }
        }

        return found ? slargest : -1;
    }
};
