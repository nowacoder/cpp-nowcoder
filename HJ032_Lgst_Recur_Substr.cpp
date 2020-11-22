#include <string>
#include <iostream>

using namespace std;

int validLen(string line) {
    if (line.length()<=1) return line.length();
    else if (line.length()==2) {
        if (line[0]==line[1]) return 2;
        else return 1;
    } else {
        int vd_ = 1;
        for (int i=0; i<line.length()-1; i++) {
            int tmp_ = 0;
            for (int j=0; (i-j>=0 and i+1+j<line.length()); j++) {
                if (line[i-j]==line[i+1+j]) tmp_ += 2;
                else break;
            }
            if (tmp_>vd_) vd_ = tmp_;
        }
        for (int i=0; i<line.length(); i++) {
            int tmp_ = 1;
            for (int j=1; (i-j>=0 and i+j<line.length()); j++) {
                if (line[i-j]==line[i+j]) tmp_ += 2;
                else break;
            }
            if (tmp_>vd_) vd_ = tmp_;
        }
        return vd_;
    }
}

int main() {
    for(string line; getline(cin, line);) {
        cout << validLen(line) << endl;
    }
    return 0;
}