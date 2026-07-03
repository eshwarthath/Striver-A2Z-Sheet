int findMin(vector<int>& arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // Search space is already sorted.
        // Then arr[low] will always be the smallest
        // element in that search space.
        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }

        // Left half is sorted.
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // Right half is sorted.
        else
        {
            high = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }

    return ans;
}
