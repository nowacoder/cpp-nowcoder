#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> proc_cmd(int n, vector<int> ps, char cmd) {
    if (n<=4) {
        ps[0] = 1;
        if (cmd=='U') {
            if (ps[1]==1) ps[1] = n;
            else ps[1] -= 1;
        } else if (cmd=='D') {
            if (ps[1]==n) ps[1] = 1;
            else ps[1] += 1;
        }
        return ps;
    } else {
        if (cmd=='U') {
            if (ps[0]==ps[1]) {
                if (ps[0] == 1) {
                    ps[0] = n-3;
                    ps[1] = n;
                } else {
                    ps[0] -= 1;
                    ps[1] -= 1;
                }
            } else {
                ps[1] -= 1;
            }
            return ps;
        } else if (cmd=='D') {
            if (ps[1]-ps[0]==3) {
                if (ps[1]==n) {
                    ps[0] = 1;
                    ps[1] = 1;
                } else {
                    ps[0] += 1;
                    ps[1] += 1;
                }
            } else {
                ps[1] += 1;
            }
            return ps;
        }
        return ps;
    }
}

int main() {
    int n;
    vector<int> ps(2);
    string cmds;
    while (cin>>n) {
        cin >> cmds;
        ps[0] = 1; ps[1] = 1;
        for (char cmd : cmds) {
            ps = proc_cmd(n, ps, cmd);
        }
        int k = n<4?n:4;
        for (int i=0; i<k; i++) {
            cout << ps[0]+i << ' ';
        }
        cout << endl;
        cout << ps[1] << endl;
    }
    return 0;
}