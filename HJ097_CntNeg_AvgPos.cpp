#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, tmp;
    cout << setprecision(1) << fixed;
    while (cin>>n) {
        int nc=0, pc=0, ps=0;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            if (tmp<0) nc++;
            else if (tmp>0) {pc++; ps+=tmp;}
        }
        cout << nc << ' ' << (float)ps/pc << endl;
    }
    return 0;
}