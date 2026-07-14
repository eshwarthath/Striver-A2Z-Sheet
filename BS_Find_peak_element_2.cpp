class Solution {
public:

    int maxelement(vector<vector<int>>& mat, int m, int n, int col) {
        int row = 0;

        for (int i = 1; i < m; i++) {
            if (mat[i][col] > mat[row][col]) {
                row = i;
            }
        }

        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m = mat.size();        // number of rows
        int n = mat[0].size();     // number of columns

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int row = maxelement(mat, m, n, mid);

            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < n) ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            }
            else if (mat[row][mid] < right) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};
