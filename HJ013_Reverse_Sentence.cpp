#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<string> sen {istream_iterator<string>(iss), {}};
    
    cout << sen[sen.size()-1];
    for (int i=sen.size()-2; i>=0; i--) {
        cout << ' ' << sen[i];
    } cout << endl;
    
    return 0;
}