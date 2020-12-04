#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    bool flag;
    for(string line; getline(cin, line);) {
        vector<string> rst;
        for (char c : line) {
            flag = false;
            for(int i=0; i<rst.size(); i++) {
                if (rst[i][0]==c) {
                    rst[i] += c;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                string str_(1,c);
                rst.push_back(str_);
            }
        }
        flag = false;
        for (string str : rst) {
            if (str.length()==1) {
                cout << str[0] << endl;
                flag = true;
                break;
            }
        }
        if (!flag) cout << -1 << endl;
    }

    return 0;
}
