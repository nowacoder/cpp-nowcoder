#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

char convert(char c) {
    if ((c>=48 and c<=57) or (c>=65 and c<=70) or (c>=97 and c<=102)) {
        if (c=='0' or c=='6' or c=='9') return c;
        else if (c=='f' or c=='F') return 'F';
        else if (c=='1') return '8';
        else if (c=='2') return '4';
        else if (c=='3') return 'C';
        else if (c=='4') return '2';
        else if (c=='5') return 'A';
        else if (c=='7') return 'E';
        else if (c=='8') return '1';
        else if (c=='A' or c=='a') return '5';
        else if (c=='B' or c=='b') return 'D';
        else if (c=='C' or c=='c') return '3';
        else if (c=='D' or c=='d') return 'B';
        else if (c=='E' or c=='e') return '7';
    } else return c;
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        string str = str1 + str2;
        if (str.length()>=3) {
            str1 = "";
            for (int i=0; i<str.length(); i+=2) str1 += str[i];
            sort(str1.begin(), str1.end());
            for (int i=0; i<str.length(); i+=2) str[i] = str1[i/2];

            str2 = "";
            for (int i=1; i<str.length(); i+=2) str2 += str[i];
            sort(str2.begin(), str2.end());
            for (int i=1; i<str.length(); i+=2) str[i] = str2[(i-1)/2];

            for (int i=0; i<str.length(); i++) str[i] = convert(str[i]);
        }

        cout << str << endl;
    }
    return 0;
}