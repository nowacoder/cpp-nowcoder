#include <string>
#include <iostream>
using namespace std;

int main() {
    string line; cin >> line;
    // initialize the array with all zeros, otherwise it might be randomly initialized
    int cnt[128] = {0}; 
    for (int i=0; i<line.size(); i++) cnt[line[i]] = 1;
    int rst = 0;
    for (int i=0; i<128; i++) rst += cnt[i];
    cout << rst << endl;
    return 0;
}