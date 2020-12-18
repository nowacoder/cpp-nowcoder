#include <string>
#include <iostream>

using namespace std;

int main() {
    string str;
    int max, tmp;
    while (cin>>str) {
        max = 1;
        for (int i=0; i<str.length(); i++) {
            tmp = 1;
            for (int j=i-1; j>=0; j--) {
                if (i+i-j>=str.length()) break;
                else if (str[j]==str[i+i-j]) tmp += 2;
                else break;
            }
            if (tmp>max) max = tmp;
            if (str[i]==str[i+1]) {
                tmp = 2;
                for (int j=i-1; j>=0; j--) {
                    if (i+1+i-j>=str.length()) break;
                    else if (str[j]==str[i+1+i-j]) tmp += 2;
                    else break;
                }
                if (tmp>max) max = tmp;
            }
        }
        cout << max << endl;
    }
    return 0;
}

