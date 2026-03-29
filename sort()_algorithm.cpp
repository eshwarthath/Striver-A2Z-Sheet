#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {5, 2, 4, 1, 3};

    sort(v.begin(), v.end());

    for(int x : v)
        cout << x << " ";

    return 0;
}
