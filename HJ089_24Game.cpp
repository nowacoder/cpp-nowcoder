#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<string>> get_combs(vector<string> cards) {
    vector<vector<string>> combs;
    vector<string> signs = {"+","-","*","/"};
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<4; k++) {
                for (int l=0; l<4; l++) {
                    for (int m=0; m<4; m++) {
                        for (int n=0; n<4; n++) {
                            for (int p=0; p<4; p++) {
                                if (k!=i and m!=i and m!=k and 
                                   p!=i and p!=k and p!=m) {
                                    vector<string>comb = {cards[i], signs[j], cards[k],
                                        signs[l], cards[m], signs[n], cards[p]};
                                    combs.push_back(comb);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return combs;
}

double eval_exp(vector<string> combs) {
    if (combs.size()==3) {
        if (combs[1]=="+") return stod(combs[0])+stod(combs[2]);
        else if (combs[1]=="-") return stod(combs[0])-stod(combs[2]);
        else if (combs[1]=="*") return stod(combs[0])*stod(combs[2]);
        else if (combs[1]=="/") return stod(combs[0])/stod(combs[2]);
    } else {
        if (combs[1]=="+") {
            vector<string> combs_;
            for (int i=2; i<combs.size(); i++) 
                combs_.push_back(combs[i]);
            return stod(combs[0])+eval_exp(combs_);
        }  else if (combs[1]=="-") {
            vector<string> combs_;
            for (int i=2; i<combs.size(); i++) {
                if (combs[i]=="+") combs_.push_back("-");
                else if (combs[i]=="-") combs_.push_back("+");
                else combs_.push_back(combs[i]);
            }
            return stod(combs[0])-eval_exp(combs_);
        } else if (combs[1]=="*") {
            vector<string> combs_ = {to_string(stod(combs[0])*stod(combs[2]))};
            for (int i=2; i<combs.size(); i++) combs_.push_back(combs[i]);
            return eval_exp(combs_);
        } else if (combs[1]=="/") {
            vector<string> combs_ = {to_string(stod(combs[0])/stod(combs[2]))};
            for (int i=2; i<combs.size(); i++) combs_.push_back(combs[i]);
            return eval_exp(combs_);
        }
    }
    return 0;
}

string cal24(vector<string> cards) {
    for (int i=0; i<4; i++) {
        if (cards[i]=="J") cards[i] = "11";
        else if (cards[i]=="Q") cards[i] = "12";
        else if (cards[i]=="K") cards[i] = "13";
        else if (cards[i]=="A") cards[i] = "1";
    }
    vector<vector<string>> combs = get_combs(cards);
    for (auto comb : combs) {
        double rst = eval_exp(comb);
        if ((rst-24.)*(rst-24.)<0.000000000001) {
            string rst_str = "";
            for (string c: comb) rst_str += c;
            return rst_str;
        }
    }
    return "NONE";
}

int main() {
    string card;
    while (cin >> card) {
        bool valid = true;
        if (card.length()>1 and card!="10") valid = false;
        vector<string> cards = {card};
        for (int i=0; i<3; i++) {
            cin >> card;
            cards.push_back(card);
            if (card.length()>1 and card!="10") valid = false;
        }
        if (not valid) cout << "ERROR" << endl;
        else {
            cout << cal24(cards) << endl;
        }
    }
    
    return 0;
}