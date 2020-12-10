#include <iostream>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >>m) {
        int rst[n+1][m+1];
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                if (i==0 or j==0) rst[i][j] = 1;
                else {
                    rst[i][j] = rst[i-1][j] + rst[i][j-1];
                }
            }
        }
        cout << rst[n][m] << endl;
    }
    
    return 0;
}