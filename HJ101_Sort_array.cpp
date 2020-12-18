#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, flag;
    while (cin >> n) {
        int nums[n];
        for (int i=0; i<n; i++) cin >> nums[i];
        cin >> flag;
        if (!flag) {
            sort(nums, nums+n);
        } else {
            sort(nums, nums+n, greater<int>());
        }
        for (int i=0; i<n; i++) cout << nums[i] << ' ';
        cout << endl;
    }
    return 0;
}