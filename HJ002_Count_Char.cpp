#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string line; getline(cin, line);
    map<char, int> data;
    for (char c:line) {
        if (97<=c and c<=122) c-=32;
        if (data.find(c)==data.end()) {
            data[c] = 1;
        } else {
            data[c] += 1;
        }
    }
    getline(cin, line);
    char k = line[0]; 
    if (97<=k and k<=122) k-=32;
    cout << data[k] << endl;
    return 0;
}
