#include <iostream>

using namespace std;

int main() {
    int n, max, t;
    while (cin>>n) {
        int nums[n], rst[n];
        for (int i=0; i<n; i++) cin >> nums[i];
        rst[0] = 1;
        max = 1;
        for (int i=1; i<n; i++) {
            t = 0;
            for (int j=0; j<i; j++) {
                if (nums[j]<nums[i] and rst[j]>t) 
                    t = rst[j];
            }
            rst[i] = t + 1;
            if (rst[i]>max) max = rst[i];
        }
        cout << max << endl;
    }
    return 0;
}