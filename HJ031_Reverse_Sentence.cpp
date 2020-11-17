#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool valid_char(char c) {
    if ((c>=65 and c<=90) or (c>=97 and c<=122)) return true;
    else return false;
}

int main() {
    string line; 
    getline(cin, line);
    string word;
    vector<string> words;
    
    word = "";
    for (char c : line) {
        if (valid_char(c)) word += c;
        else {
            if (word.length()>0) {
                words.push_back(word);
                word = "";
            }
        }
    }
    if (word.length()>0) words.push_back(word);
    
    string out = "";
    for (int i=words.size()-1; i>=0; i--) out += words[i]+" ";
    out[out.length()-1] = '\n';
    cout << out;
    
    return 0;
}