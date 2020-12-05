#include <iostream>

using namespace std;

// place apples in the way that plate i+1 has no less than plate i's apples
int combos(int m, int n, int ub, int lb) {
    if (m<=1 or n==1) return 1;
    else if (n==2) return (m+2)/2-lb;
    int rst = 0;
    for (int i=lb; i<=ub; i++) {
        rst += combos(m-i, n-1, (m-i)/(n-1), i);
    }
    return rst;
}

int main() {
    int m, n;
    while (cin>>m>>n) {
        cout << combos(m,n,m/n,0) << endl;
    }
    return 0;
}