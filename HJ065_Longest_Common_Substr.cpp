#include <string>
#include <iostream>

using namespace std;

int main() {
    string str1, str2, tmp;
    int l1, l2, mx, mp;
    while (getline(cin, str1)) {
        getline(cin, str2);
        l1 = str1.length();
        l2 = str2.length();
        // make sure the 1st result from 
        // the shorter str is the ouput
        if (l1>l2) {
            tmp = str1;
            str1 = str2;
            str2 = tmp;
        }
        l1 = str1.length();
        l2 = str2.length();
        int mat[l1][l2];
        mx = 0; mp = 0;
        for (int i=0; i<l1; i++) {
            for (int j=0; j<l2; j++) {
                if (str1[i]!=str2[j]) mat[i][j] = 0;
                else {
                    if (i==0 or j==0) mat[i][j] = 1;
                    else mat[i][j] = mat[i-1][j-1] + 1;
                }
                if (mat[i][j]>mx) {
                    mx = mat[i][j];
                    mp = j;
                }
            }
        }
        cout << str2.substr(mp-mx+1, mx) << endl;
    }
    return 0;
}