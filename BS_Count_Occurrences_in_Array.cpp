class Solution {
public:
    int countOccurrences(vector<int>& arr, int target) {
        int n = arr.size();

        // Find first occurrence
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // Target not found
        if (first == -1) {
            return 0;
        }

        // Find last occurrence
        low = 0;
        high = n - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return last - first + 1; // if we subract first and last then we add+1 we get the occurence.
      
    }
};
