#include <string>
#include <iostream>
using namespace std;

int digi_sum(char c1, char c2) {
    int d1 = c1 - 48;
    int d2 = c2 - 48;
    return d1 + d2;
}

string Big_Sum(string int1, string int2) {
    int len1 = int1.length();
    int len2 = int2.length();
    int k = len1<len2?len1:len2;
    int flag = 0, d;
    string rst = "";
    for (int i=1; i<=k; i++) {
        d = digi_sum(int1[len1-i], int2[len2-i]);
        d += flag;
        if (d>=10) {flag = 1; d = d - 10;}
        else flag = 0;
        rst = (char)(d+48) + rst;
    }
    if (len1==len2) {
        if (flag) rst = '1'+rst;
        return rst;
    } else if (len1>len2) {
        for (int i=k+1; i<=len1; i++) {
            d = flag + (int1[len1-i]-48);
            if (d>=10) {flag = 1; d = d - 10;}
            else flag = 0;
            rst = (char)(d+48) + rst;
        }
    } else {
        for (int i=k+1; i<=len2; i++) {
            d = flag + (int2[len2-i]-48);
            if (d>=10) {flag = 1; d = d - 10;}
            else flag = 0;
            rst = (char)(d+48) + rst;
        }
    }
    if (flag) rst = '1'+rst;
    return rst;
}

int main() {
    string int1, int2;
    int len1, len2;
    while (cin>>int1) {
        cin >> int2;
        cout << Big_Sum(int1, int2) << endl;
    }
    return 0;
}