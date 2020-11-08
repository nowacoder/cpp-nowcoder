#include <iostream>

using namespace std;

int main() {
    float num; 
    cin >> num;
    int rst = (int)num;

    if (num>=(float)rst+0.5) cout << rst+1 << endl;
    else cout << rst << endl;

    return 0;
}