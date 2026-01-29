#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Function to find maximum of four numbers
int max_of_four(int a, int b, int c, int d) {
    int maxVal = a;

    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
    if (d > maxVal) maxVal = d;

    return maxVal;
}

int main() {
    int a, b, c, d;

    // Read four integers (one per line)
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    // Print the maximum
    cout << max_of_four(a, b, c, d);

    return 0;
}
