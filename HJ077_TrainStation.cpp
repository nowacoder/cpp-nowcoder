#include <stack>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> get_seq(queue<int> que, stack<int> stk, vector<int> comb) {
    vector<vector<int>> rst;
    int tr;
    
    if (que.size()==0 and stk.size()==0) {
        rst.push_back(comb);
    } else if (que.size()>0 and stk.size()==0) {
        tr = que.front();
        que.pop();
        stk.push(tr);
        vector<vector<int>> rst_ = get_seq(que, stk, comb);
        for(auto comb_ : rst_) rst.push_back(comb_);
    } else if (que.size()==0 and stk.size()>0) {
        tr = stk.top();
        stk.pop();
        comb.push_back(tr);
        vector<vector<int>> rst_ = get_seq(que, stk, comb);
        for(auto comb_ : rst_) rst.push_back(comb_);
    } else {
        // when there are trains both in queue (to station) and in stack (already in station)
        // there are two cases, case 1: pop a train from stk but no train enters
        tr = stk.top();
        stk.pop();
        comb.push_back(tr);
        vector<vector<int>> rst_ = get_seq(que, stk, comb);
        for(auto comb_ : rst_) rst.push_back(comb_);
        // revert the status for case 2
        tr = comb[comb.size()-1];
        comb.pop_back();
        stk.push(tr);
        // case 2: move a train from queue to stk (station)
        tr = que.front();
        que.pop();
        stk.push(tr);
        rst_ = get_seq(que, stk, comb);
        for(auto comb_ : rst_) rst.push_back(comb_);
    }
    
    return rst;
}

bool larger_equal(vector<int> a, vector<int> b) {
    for (int i=0; i<a.size(); i++) {
        if (a[i]<b[i]) return false;
        else if (a[i]>b[i]) return true;
    }
    return true;
}

void sort_print(vector<vector<int>> rst) {
    vector<int> tmp;
    for (int i=1; i<rst.size(); i++) {
        for (int j=i-1; j>=0; j--) {
            if (!larger_equal(rst[j+1], rst[j])) {
                tmp = rst[j];
                rst[j] = rst[j+1];
                rst[j+1] = tmp;
            } else break;
        }
    }
    for (auto comb_ : rst) {
        for (int i : comb_) {
            cout << i << ' ';
        } cout << endl;
    }
}

int main() {
    int n, t;
    while (cin>>n) {
        queue<int> que;
        for (int i=0; i<n; i++) {
            cin >> t;
            que.push(t);
        }
        stack<int> stk;
        vector<int> comb;
        vector<vector<int>> rst = get_seq(que, stk, comb);
        sort_print(rst);
    }
    return 0;
}