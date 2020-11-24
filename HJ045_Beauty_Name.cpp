#include <string>
#include <iostream>

using namespace std;

int cal_beauty(string name) {
    int bd = 0;
    int cnt[26] = {0};
    for (char c : name) {
        if (c>=97 and c<=122) cnt[c-97] += 1;
        else if (c>=65 and c<=90) cnt[c-65] += 1;
    }
    int max = 1, max_, bd_;
    while (max>0) {
        max_ = 0;
        bd_ = 26;
        for (int i=0; i<26; i++) {
            if (cnt[i]>0) {
                bd += bd_;
                bd_--;
                cnt[i]--;
                if (cnt[i]>max_) max_ = cnt[i];
            }
        }
        max = max_;
    }
    return bd;
}

int main() {
    int n; 
    string name;
    int bd;
    while (cin>>n) {
        for (int i=0; i<n; i++) {
            // getline(cin, name);
            cin >> name;
            bd = cal_beauty(name);
            cout << bd << endl;
        }
    }
    return 0;
}