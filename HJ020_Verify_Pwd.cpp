#include <string>
#include <iostream>

using namespace std;

int get_max_repeat(string la, string lb) {
    int max_repeat = 0;
    int len = la.length()<lb.length()?la.length():lb.length();
    int repeat = 0;
    for (int i=0; i<len; i++) {
        if (la[i]==lb[i]) {
            repeat++;
            if (repeat>max_repeat) max_repeat = repeat;
        } else repeat = 0;
    }
    return max_repeat;
}

int cal_max_repeat(string line) {
    int max_repeat = 0;
    string sub_line;
    int repeat = 0;
    for (int i=1; i<line.length(); i++) {
        sub_line = line.substr(i);
        repeat = get_max_repeat(line, sub_line);
        if (repeat>max_repeat) max_repeat = repeat;
    }
    return max_repeat;
}

int main() {
    for (string line; getline(cin, line);) {
        if (line.length()<=8) cout << "NG" << endl;
        else if (cal_max_repeat(line)>2) cout << "NG" << endl;
        else {
            int n_cnt = 0, u_cnt = 0, l_cnt = 0, s_cnt = 0;
            for (char c : line) {
                if (c>=48 and c<=57) n_cnt = 1;
                else if (c>=65 and c<=90) u_cnt = 1;
                else if (c>=97 and c<=122) l_cnt = 1;
                else s_cnt = 1;
            }
            if (n_cnt + u_cnt + l_cnt + s_cnt >= 3) cout << "OK" << endl;
            else cout << "NG" << endl;
        }
    }
    return 0;
}