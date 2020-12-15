#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        vector<string> rst;
        string tmp = "";
        bool num_flag = false;
        for (char c : line) {
            if (c<48 or c>57) {
                if (num_flag) {
                    rst.push_back(tmp);
                    tmp = "";
                }
                tmp += c;
                num_flag = false;
            } else {
                if (!num_flag) {
                    if (tmp.length()>0) 
                        rst.push_back(tmp);
                    tmp = "";
                }
                tmp += c;
                num_flag = true;
            }
        }
        rst.push_back(tmp);
        for (string tmp_ : rst) {
            if (tmp_[0]>=48 and tmp_[0]<=57) 
                cout << '*' << tmp_ << '*';
            else cout << tmp_;
        } cout << endl;
        
    }
    return 0;
}