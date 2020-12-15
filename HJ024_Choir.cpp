#include <iostream>

using namespace std;

int main() {
    int n;
    int mx;
    while (cin >> n) {
        int nums[n];
        for (int i=0; i<n; i++) cin >> nums[i];
        int la[n], ra[n];
        // longest number of ascending items
        for (int i=0; i<n; i++) {
            mx = 0;
            for (int j=0; j<i; j++) {
                if (nums[j]<nums[i] and la[j]>mx) mx = la[j];
            }
            la[i] = mx+1;
        }
        // longest number of descening items
        for (int i=n-1; i>=0; i--) {
            mx = 0;
            for (int j=n-1; j>i; j--) {
                if (nums[j]<nums[i] and ra[j]>mx) mx = ra[j];
            }
            ra[i] = mx+1;
        }
        mx = 0;
        for (int i=0; i<n; i++) {
            if (la[i]+ra[i]>mx) mx = la[i]+ra[i];
        }
        cout << n-mx+1 << endl;
    }
    return 0;
}