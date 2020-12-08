#include <string>
#include <vector>
#include <iostream>

using namespace std;

// evaluation expressions without parentheses
string eval_exp_simple(vector<string> exp_vec) {
    if (exp_vec.size()==1) return exp_vec[0];
    else if (exp_vec.size()==3) {
        int left = stoi(exp_vec[0]);
        char sign = exp_vec[1][0];
        int right = stoi(exp_vec[2]);
        if (sign=='+') return to_string(left+right);
        else if (sign=='-') return to_string(left-right);
        else if (sign=='*') return to_string(left*right);
        else if (sign=='/') return to_string(left/right);
    } else {
        if (exp_vec[1]=="+" or exp_vec[1]=="-") {
            vector<string> exp_vec_;
            exp_vec_.push_back(exp_vec[0]);
            exp_vec_.push_back(exp_vec[1]);
            vector<string> exp_vec__;
            for (int i=2; i<exp_vec.size(); i++) {
                if (exp_vec[1]=="-" and exp_vec[i]=="+") 
                    exp_vec__.push_back("-");
                else if (exp_vec[1]=="-" and exp_vec[i]=="-") 
                    exp_vec__.push_back("+");
                else 
                    exp_vec__.push_back(exp_vec[i]);
            }
            exp_vec_.push_back(eval_exp_simple(exp_vec__));
            return eval_exp_simple(exp_vec_);
        } else if (exp_vec[1]=="*" or exp_vec[1]=="/") {
            vector<string> exp_vec__;
            for (int i=0; i<3; i++) exp_vec__.push_back(exp_vec[i]);
            vector<string> exp_vec_;
            exp_vec_.push_back(eval_exp_simple(exp_vec__));
            for (int i=3; i<exp_vec.size(); i++) exp_vec_.push_back(exp_vec[i]);
            return eval_exp_simple(exp_vec_);
        }
    }
    return "";
}

string eval_exp(vector<string> exp_vec) {
    vector<string> exp_vec_;
    for (int i=0; i<exp_vec.size(); i++) {
        // evaluate expressions in parentheses first
        if (exp_vec[i]=="{" or exp_vec[i]=="[" or exp_vec[i]=="(") {
            int cnt = 1;
            vector<string> exp_vec_in;
            while (cnt>=1) {
                i++;
                exp_vec_in.push_back(exp_vec[i]);
                if (exp_vec[i]=="{" or exp_vec[i]=="[" or exp_vec[i]=="(") cnt++;
                else if (exp_vec[i]=="}" or exp_vec[i]=="]" or exp_vec[i]==")") {
                    cnt--;
                }
            }
            exp_vec_in.pop_back();
            exp_vec_.push_back(eval_exp(exp_vec_in));
        } else {
            exp_vec_.push_back(exp_vec[i]);
        }
    }
    
    return eval_exp_simple(exp_vec_);
}

int main() {
    string exp_str;
    while (cin>>exp_str) {
        vector<string> exp_vec;
        // split the input to segments
        exp_vec.push_back(exp_str.substr(0,1));
        for (int i=1; i<exp_str.length(); i++) {
            if (exp_str[i]>=48 and exp_str[i]<=57) {
                if (exp_str[i-1]>=48 and exp_str[i-1]<=57) 
                    exp_vec[exp_vec.size()-1] += exp_str[i];
                else if (exp_str[i-1]=='-') {
                    if (exp_vec.size()==1) 
                        exp_vec[0] += exp_str[i];
                    else if ( (exp_str[i-2]>=48 and exp_str[i-2]<=57) or 
                             exp_str[i-2]=='}' or exp_str[i-2]==']' or exp_str[i-2]==')' )
                        exp_vec.push_back(exp_str.substr(i,1));
                    else 
                        exp_vec[exp_vec.size()-1] += exp_str[i];
                } else
                    exp_vec.push_back(exp_str.substr(i,1));
            } else 
                exp_vec.push_back(exp_str.substr(i,1));
        }
        cout << eval_exp(exp_vec) << endl;
    }
    return 0;
}