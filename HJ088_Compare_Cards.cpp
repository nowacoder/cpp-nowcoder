#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

bool isJoker(vector<string> h) {
    if (h.size()==2 and 
        ( (h[0]=="joker" and h[1]=="JOKER") or 
          (h[0]=="joker" and h[1]=="JOKER") ) )
        return true;
    else return false;
}

int ctoi(string card) {
    if (card=="10") return 10;
    else if (card=="J") return 11;
    else if (card=="Q") return 12;
    else if (card=="K") return 13;
    else if (card=="A") return 14;
    else if (card=="2") return 15;
    else return card[0]-48;
}

int compare(vector<string> h1, vector<string> h2) {
    if (isJoker(h1)) return 1;
    else if (isJoker(h2)) return 0;
    else if (h1.size()==h2.size()) {
        int i1 = ctoi(h1[0]);
        int i2 = ctoi(h2[0]);
        if (i1>i2) return 1;
        else return 0;
    } else {
        if (h1.size()==4) return 1;
        else if (h2.size()==4) return 0;
        else return -1;
    }
} 

int main() {
    string line, hand1, hand2, card;
    while (getline(cin, line)) {
        stringstream ss(line);
        getline(ss, hand1, '-');
        getline(ss, hand2, '-');
        stringstream ss1(hand1);
        vector<string> h1;
        while (ss1.good()) {
            getline(ss1, card, ' ');
            h1.push_back(card);
        }
        stringstream ss2(hand2);
        vector<string> h2;
        while (ss2.good()) {
            getline(ss2, card, ' ');
            h2.push_back(card);
        }
        int rst = compare(h1, h2);
        if (rst==1) cout << hand1 << endl;
        else if (rst==0) cout << hand2 << endl;
        else cout << "ERROR" << endl;
    }
    
    return 0;
}