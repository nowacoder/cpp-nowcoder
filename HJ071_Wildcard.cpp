#include <string>
#include <iostream>

using namespace std;

bool matched(string ptn, string str) {
    if (ptn.length()==1) {
        if (ptn[0]=='*') {
            return true;
        } else {
            if (str.length()>1) return false;
            else {
                if (ptn[0]=='?') return true;
                else if (ptn[0]==str[0]) return true;
                else return false;
            }
        }
    } else {
        if (ptn[0]=='*') {
            char nptn = ptn[1];
            bool rst = false;
            for (int i=0; i<str.length()-1; i++) {
                if (str[i]==nptn or nptn=='?') {
                    rst = rst or matched(ptn.substr(2, ptn.length()),
                                        str.substr(i+1, str.length()));
                    if (rst) return rst;
                } 
            }
            // case: lzgotxxp*o?q?xnctvqxc*f, lzgotxxprorqbxnctvqxclf
            if (ptn.length()==2 and (str[str.length()-1]==nptn or nptn=='?')) return true;
            return rst;
        } else if (ptn[0]=='?') 
            return matched(ptn.substr(1,ptn.length()),
                           str.substr(1,str.length()));
        else {
            if (ptn[0]==str[0])
                return matched(ptn.substr(1,ptn.length()),
                               str.substr(1,str.length()));
            else return false;
        }
    }
}


int main() {
    string ptn, str;
    while (cin >> ptn) {
        cin >> str;
        if (matched(ptn, str)) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}