#include <string>
#include <iostream>

using namespace std;

int main() {
    string line;
    // for (string line; getline(cin, line);) {
    while (cin>>line) {
        if (line.length()==0) continue;
        else {
            int rows = line.length()/8+(line.length()%8!=0);
            int pst = 0;
            for (int i=0; i<rows; i++) {
                for (int j=0; j<8; j++) {
                    pst = i*8 + j;
                    if (pst<line.length()) cout << line[pst];
                    else cout << '0';
                } cout << endl;
            }
        }
    }
    return 0;
}