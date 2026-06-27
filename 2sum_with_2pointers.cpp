int n = arr.size();

int left = 0;
int right = n - 1;

while (left < right) {
    if (arr[left] + arr[right] == target) {
        return {left, right};
    }
    else if (arr[left] + arr[right] > target) {
        right--;
    }
    else {
        left++;
    }
}
