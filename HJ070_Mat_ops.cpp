#include <array>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Mat {
    int m, n, o=0;
    Mat(int m_, int n_): m(m_), n(n_) {}
    Mat(int m_, int n_, int ops_): m(m_), n(n_), o(ops_) {}
};

vector<string> exp_seg(string exp) {
    vector<string> exp_segs;
    char c;
    int s_, e_, cnt=0;
    for (int i=0; i<exp.length(); i++) {
        c = exp[i];
        if (c=='(') {
            cnt++;
            if (cnt==1) s_ = i;
        } else if (c==')') {
            cnt--;
            if (cnt==0) {
                e_ = i;
                exp_segs.push_back(exp.substr(s_+1, e_-s_-1));
            }
        } else {
            if (cnt==0) {
                string seg = "";
                exp_segs.push_back(seg+c);
            }
        }
    }
    return exp_segs;
}

Mat num_multiplies(string exp, vector<array<int,2>> dims) {
    vector<string> exp_segs = exp_seg(exp);
    vector<Mat> mats;
    for (string seg_ : exp_segs) {
        if (seg_.length()==1) mats.push_back(Mat(dims[seg_[0]-65][0], dims[seg_[0]-65][1]));
        else mats.push_back(num_multiplies(seg_, dims));
    }
    
    int s_, e_, m_, n_;
    s_ = mats[0].m; 
    m_ = mats[0].n;
    e_ = mats[mats.size()-1].n;
    int ops = mats[0].o;
    for (int i=1; i<mats.size(); i++) {
        Mat mat = mats[i];
        n_ = mat.n;
        ops += mat.o;
        ops += s_ * m_ * n_;
        m_ = n_;
    }
    return Mat(s_, e_, ops);
}

int main() {
    int n;
    string exp;
    
    while (cin >> n) {
        vector<array<int,2>> dims(n);
        for (int i=0; i<n; i++) {
            cin >> dims[i][0] >> dims[i][1];
        }
        cin >> exp;
        cout << num_multiplies(exp.substr(1,exp.length()-2), dims).o << endl;
    }
    
    return 0;
}