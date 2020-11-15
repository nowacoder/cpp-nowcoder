#include <string>
#include <iostream>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;
    int len1 = str1.length();
    int len2 = str2.length();
    if (!len1 or !len2) return -1;
    int rst[len1][len2];
    int max = 0, loc1, loc2;
    for (int i=0; i<len1; i++) {
        for (int j=0; j<len2; j++) {
            if (str1[i]==str2[j]) {
                if (i==0 or j==0) rst[i][j] = 1;
                else rst[i][j] = rst[i-1][j-1] + 1;
                if (rst[i][j]>max) {
                    max = rst[i][j];
                    loc1 = i;
                    loc2 = j;
                    cout << max << ' ' << loc1 << ' ' << loc2 << endl;
                } 
            } else rst[i][j] = 0;
        }
    }
    if (max==0) return -1;
    cout << str1.substr(loc1-max+1,max) << endl;
    return 0;
}