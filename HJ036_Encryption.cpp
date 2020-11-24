#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    string keyword, keyphrase;
    bool flag;
    while (getline(cin, keyword)) {
        getline(cin, keyphrase);
        vector<char> encrypt; // make sure it's cleared each run
        for (char c : keyword) {
            if (c>=97) c = c-97+65;
            flag = false;
            for (char c_ : encrypt) {
                if (c==c_) {
                    flag = true;
                    break;
                }
            }
            if (!flag) encrypt.push_back(c);
        }
        for (char i=65; i<=90; i++) {
            flag = false;
            for (char c_ : encrypt) {
                if (i==c_) {
                    flag = true;
                    break;
                }
            }
            if (!flag) encrypt.push_back(i);
        }
        for (char c : keyphrase) {
            if (c>=97 and c<=122) cout << (char)(encrypt[c-97]-65+97);
            else if (c>=65 and c<=90) cout << encrypt[c-65];
            else cout << c;
        }
        cout << endl;
    }
    return 0;
}