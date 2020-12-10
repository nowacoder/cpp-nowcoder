#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isSibling(string word, string wd) {
    if (word.length()!=wd.length()) return false;
    else if (word==wd) return false;
    else {
        int cnt[128] = {0};
        for (char c : word) cnt[c-0] += 1;
        for (char c : wd) cnt[c-0] -= 1;
        for (int i=0; i<128; i++) {
            if (cnt[i]!=0) return false;
        }
        return true;
    }
}

vector<string> sort_dict(vector<string> words) {
    vector<string> swords;
    swords.push_back(words[0]);
    string word, tmp;
    for (int i=1; i<words.size(); i++) {
        word = words[i];
        for (int j=0; j<swords.size(); j++) {
            if (word<swords[j]) {
                tmp = swords[j];
                swords[j] = word;
                word = tmp;
            } 
        }
        // there may be repeated sibling words
        if (word>=swords[swords.size()-1]) 
            swords.push_back(word);
    }
    return swords;
}

int main() {
    int n, k;
    string word;
    while (cin>>n) {
        vector<string> words;
        for (int i=0; i<n; i++) {
            cin >> word;
            words.push_back(word);
        }
        cin >> word; 
        cin >> k;
        vector<string> siblings;
        for (string wd : words) {
            if (isSibling(word, wd)) 
                siblings.push_back(wd);
        }
        // there may be no qualified sibling words
        if (siblings.size()>0)
            siblings = sort_dict(siblings);
        cout << siblings.size() << endl;
        // k might be larger than the number of sibling words
        if (k<=siblings.size()) 
            cout << siblings[k-1] << endl;
    }
    return 0;
}