#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

void Sort_String_Vec(vector<string> input) {
    string tmp;
    for (int i=1; i<input.size(); i++) {
        for (int j=i-1; j>=0; j--) {
            if (input[j+1]<input[j]) {
                tmp = input[j+1];
                input[j+1] = input[j];
                input[j] = tmp;
            } else break;
        }
    }
    cout << input[0];
    for (int i=1; i<input.size(); i++) {
        cout << ',' << input[i];
    } cout << endl;
}

int main() {
    for (string line; getline(cin, line);) {
        vector<string> input;
        stringstream ss(line);
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            input.push_back(substr);
        }

        Sort_String_Vec(input);
    }
    return 0;
}