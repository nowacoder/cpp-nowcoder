#include <string>
#include <iostream>

using namespace std;

int hex2dec(char c) {
    if (48<=c and c<=57) return c-48;
    else if (65<=c and c<=70) return c-65+10;
    else if (97<=c and c<=102) return c-97+10;
    else cout << c << endl;
}

int main() {
    for (string line; getline(cin, line);) {
        char c;
        int rst = 0;
        for (int i=2; i<line.length(); i++) {
            rst = rst*16 + hex2dec(line[i]);
        }
        cout << rst << endl;
    }
    return 0;
}