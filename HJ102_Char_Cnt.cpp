#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct counter {
    char c;
    int cnt;
    counter(char c_, int cnt_): c(c_), cnt(cnt_) {}
};

int main() {
    string line;
    while (cin>>line) {
        int cnt[128] = {0};
        for (char c : line) cnt[c] += 1;
        vector<counter> rst;
        for (int i=0; i<128; i++) {
            if (cnt[i]>0) {
                counter cntr((char)i, cnt[i]);
                rst.push_back(cntr);
                for (int j=rst.size()-1; j>0; j--) {
                    if ((rst[j].cnt>rst[j-1].cnt) or 
                        (rst[j].cnt==rst[j-1].cnt and rst[j].c<rst[j-1].c)) {
                        counter tmp = rst[j];
                        rst[j] = rst[j-1];
                        rst[j-1] = tmp;
                    }
                    else break;
                }
            }
        }
        for (counter tmp : rst) cout << tmp.c;
        cout << endl;
    }
    return 0;
}