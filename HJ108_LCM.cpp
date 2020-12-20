#include <vector>
#include <iostream>

using namespace std;

int mcm(int m, int n) {
    if (m==1) return n;
    else if (n==1) return m;
    else {
        vector<int> rst;
        for (int i=2; i<=m and i<=n; i++) {
            while (m%i==0 and n%i==0) {
                rst.push_back(i);
                m /= i;
                n /= i;
            }
        }
        int mcm_ = 1;
        for (int i : rst) mcm_ *= i;
        mcm_ *= m * n;
        return mcm_;
    }
}

int main() {
    int m, n;
    while (cin >> m >> n)
        cout << mcm(m, n) << endl;
    return 0;
}