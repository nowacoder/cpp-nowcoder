#include <string>
#include <iostream>

using namespace std;

int ltoi(char c) {
    switch(c) {
        case 'a':
        case 'b':
        case 'c':
            return 2;
        case 'd':
        case 'e':
        case 'f':
            return 3;
        case 'g':
        case 'h':
        case 'i':
            return 4;
        case 'j':
        case 'k':
        case 'l':
            return 5;
        case 'm':
        case 'n':
        case 'o':
            return 6;
        case 'p':
        case 'q':
        case 'r':
        case 's':
            return 7;
        case 't':
        case 'u':
        case 'v':
            return 8;
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            return 9;
    }
}


int main() {
    for (string line; getline(cin, line);) {
        for (char c: line) {
            if (c>=97 and c<=122) {
                cout << ltoi(c);
            } else if (c>=65 and c<=89) {
                cout << (char)(c+33);
            } else if (c==90) cout << 'a';
            else cout << c;
        }
        cout << endl;
    }
    return 0;
}