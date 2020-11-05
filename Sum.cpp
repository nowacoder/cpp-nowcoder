#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
// #include <iomanip>

using namespace std;

int main() {
    for (string line; getline(cin, line);) {
        istringstream iss(line);
        vector<long> input {istream_iterator<long>(iss), {}};
        long rst = 0;
        for (int i=0; i<input.size(); i++) {
            rst += input[i];
        }
        cout << rst << endl;
    }
    return 0;
}