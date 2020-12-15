#include <iostream>

using namespace std;

void combs(int n, int pst, int tw, int ws[], int cnt[], bool wall[]) {
    if (pst<n-1) {
        for (int i=0; i<=cnt[pst]; i++) {
            combs(n, pst+1, tw+ws[pst]*i, ws, cnt, wall);
        } 
    } else {
        for (int i=0; i<=cnt[pst]; i++) {
            wall[tw+ws[pst]*i] = true;
        }
    }
}

int main() {
    int n, tcnt;
    while (cin >> n) {
        int ws[n], cnt[n];
        for (int i=0; i<n; i++) cin >> ws[i];
        for (int i=0; i<n; i++) cin >> cnt[i];
        bool wall[12001] = {false};
        int tw = 0;
        combs(n, 0, tw, ws, cnt, wall);
        tcnt = 0;
        for (int i=0; i<12001; i++) {
            if (wall[i]) tcnt++;
        }
        cout << tcnt << endl;
    }
    return 0;
}