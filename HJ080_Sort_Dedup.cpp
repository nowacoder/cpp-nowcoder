#include <vector>
#include <iostream>

using namespace std;

vector<int> sort_dedup(vector<int> mn) {
    vector<int> rst = {mn[0]};
    bool flag;
    for (int i=1; i<mn.size(); i++) {
        flag = false;
        for (int j=0; j<rst.size(); j++) {
            if (rst[j]==mn[i]) {
                flag = true;
                break;
            }
        }
        if (!flag) rst.push_back(mn[i]);
    }
    
    int tmp;
    // remember that vector is passed by value
    for (int i=1; i<rst.size(); i++) {
        for (int j=i-1; j>=0; j--) {
            if (rst[j+1]<rst[j]) {
                tmp = rst[j];
                rst[j] = rst[j+1];
                // swap in place
                rst[j+1] = tmp;
            } else break;
        }
    }
    
    return rst;
}

int main() {
    int m, n, tmp;
    while (cin >> m) {
        vector<int> mn;
        for (int i=0; i<m; i++) {
            cin >> tmp;
            mn.push_back(tmp);
        }
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            mn.push_back(tmp);
        }
        auto rst = sort_dedup(mn);
        for (auto tmp_ : rst) cout << tmp_;
        cout << endl;
    }
}