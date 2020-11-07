#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, x;
    vector<int>::iterator it;
    for (string line; getline(cin, line); ) {
        n = stoi(line);
        vector<int> input;
        for (int i=0; i<n; i++) {
            getline(cin, line);
            x = stoi(line);
            if (input.size()==0) input.push_back(x);
            else if (input.size()==1) {
                if (input[0]<x) input.push_back(x);
                else if (input[0]>x) input.insert(input.begin(), x);
            } else {
                if (input[0]>x) input.insert(input.begin(), x);
                else {
                    it = input.begin();
                    for (int k=0; k<input.size()-1; k++) {
                        it++;
                        if (input[k]<x and x<input[k+1]) {
                            input.insert(it, x);
                            break;
                        }
                    }
                    if (input[input.size()-1]<x) input.push_back(x);
                }
            }
        }
        for (int i=0; i<input.size(); i++) cout << input[i] << endl;
    }
    return 0;
}