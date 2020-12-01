#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2;
    int len1, len2;
    while (getline(cin, str1)) {
        getline(cin, str2);
        len1 = str1.length();
        len2 = str2.length();
        if (len1==0 or len2==0) return max(len1, len2);
        int mat[len1+1][len2+1];
        for (int i=0; i<=len1; i++) {
            for (int j=0; j<=len2; j++) {
                if (i==0) mat[i][j] = j;
                else {
                    if (j==0) mat[i][j] = i;
                    else {
                        if (str1[i-1]==str2[j-1]) mat[i][j] = mat[i-1][j-1];
                        else mat[i][j] = min(min(mat[i-1][j-1], mat[i-1][j]), mat[i][j-1]) + 1;
                    }
                }
            }
        }
        cout << mat[len1][len2] << endl;
    }
    return 0;
}