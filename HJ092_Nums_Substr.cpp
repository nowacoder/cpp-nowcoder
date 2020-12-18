#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string str, tmp;
    int max;
    while (cin>>str) {
        str += 'z';
        tmp = "";
        max = 0;
        vector<string> rst;
        for (char c : str) {
            if (c<48 or c>57) {
                if (tmp.length()>0) {
                    if (tmp.length()>max) 
                        max = tmp.length();
                    rst.push_back(tmp);
                    tmp = "";
                }
            } else tmp += c;
        }
        for (string tmp_ : rst) {
            if (tmp_.length()==max) cout << tmp_;
        } 
        cout << ',' << max << endl;
    }
    return 0;
}