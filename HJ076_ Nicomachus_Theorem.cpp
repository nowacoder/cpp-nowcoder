#include <iostream>

using namespace std;

int main() {
    int n, n2, n3;
    string rst;
    while (cin>>n) {
        if (n==1) cout << '1' << endl;
        else if (n==2) cout << "3+5" << endl;
        else {
            n2 = n*n;
            n3 = n*n*n;
            if (n%2==0) {
                rst = to_string(n2-1) + '+' + to_string(n2+1);
                for (int i=1; i<n/2; i++) {
                    rst = to_string(n2-1-i*2) + '+' + rst + '+' + to_string(n2+1+i*2);
                }
            } else {
                rst = to_string(n2);
                for (int i=1; i<=n/2; i++) {
                    rst = to_string(n2-i*2) + '+' + rst + '+' + to_string(n2+i*2);
                }
            }
            cout << rst << endl;
        }
    }
    return 0;
}