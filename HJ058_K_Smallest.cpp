#include <iostream>

using namespace std;

int main() {
    int n, k, tmp, m, tmp2;
    bool flag;
    while (cin >> n >> k) {
        int knums[k];
        for (int i=0; i<n; i++) {
            cin >> tmp;
            m = i>k-1?k:i;
            flag = false;
            for (int j=0; j<m; j++) {
                if (tmp<=knums[j]) {
                    flag = true;
                    for (int l=j; l<m; l++) {
                        tmp2 = knums[l];
                        knums[l] = tmp;
                        tmp = tmp2;
                    }
                    if (m<k) knums[m] = tmp;
                    break;
                }
            }
            if (!flag and m<k) knums[m] = tmp;
        }
        cout << knums[0];
        for (int i=1; i<k; i++) {
            cout << ' ' << knums[i];
        } cout << endl;
    }
    
    return 0;
}