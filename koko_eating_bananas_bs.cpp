#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calculateHours(vector<int>& piles, int k) {
        long long totalHours = 0;

        for (int i = 0; i < piles.size(); i++) {
            totalHours += (piles[i] + k - 1) / k; // ceil division
        }

        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long hours = calculateHours(piles, mid);

            if (hours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
