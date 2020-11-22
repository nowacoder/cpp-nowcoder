#include <vector>
#include <iostream>
using namespace std;

int get_len(long l) {
    int len = 1;
    long mask = 10;
    // cases of l: 10, 100, etc.
    while (mask<=l) {
        mask *= 10;
        len++;
    }
    return len;
}

bool check(long r, int len_r, long i) {
    int len_i = get_len(i);
    if (len_i<len_r) return false;
    else {
        long mask = 1;
        for (int j=0; j<len_r; j++) mask *= 10;
        for (int j=0; j<len_i-len_r+1; j++) {
            if (i%mask==r) return true;
            else i/=10;
        }
        return false;
    }
}

vector<int> proc(long r, long I[], int n_I) {
    int len_r = get_len(r);
    vector<int> rst;
    for (int i=0; i<n_I; i++) {
        if (check(r, len_r, I[i])) rst.push_back(i);
    }
    // for (int i : rst) cout << i << ',' << I[i] << endl;
    return rst;
}

vector<long> sort(long R[], int n_R) {
    vector<long> R_sorted;
    bool flag;
    for (int i=0; i<n_R; i++) {
        flag = false;
        for (int j=0; j<R_sorted.size(); j++) {
            if (R[i]<R_sorted[j]) {
                R_sorted.insert(R_sorted.begin()+j, R[i]);
                flag = true;
                break;
            } else if (R[i]==R_sorted[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) R_sorted.push_back(R[i]);
    }
    return R_sorted;
}

int main() {
    // it's possible to have multiple test cases
    for (int n_I; cin >> n_I;) {
        long I[n_I];
        for (int i=0; i<n_I; i++) cin >> I[i];
        int n_R; cin >> n_R;
        long R[n_R];

        for (int i=0; i<n_R; i++) cin >> R[i];

        vector<long> R_sorted = sort(R, n_R);
        n_R = R_sorted.size();

        vector<vector<int>> rst_all;
        for (long r : R_sorted) rst_all.push_back(proc(r, I, n_I));

        int rst_len = 0;
        for (auto rst: rst_all) {
            if (rst.size()>0) rst_len += (rst.size()+1)*2;
        }

        cout << rst_len;
        for (int i=0; i<n_R; i++) {
            auto rst = rst_all[i];
            if (rst.size()>0) {
                cout << ' ' << R_sorted[i] << ' ' << rst.size();
            }
            for (int j: rst) {
                cout << ' ' << j << ' ' << I[j];
            }
        } cout << endl;
    }
    
    return 0;
}