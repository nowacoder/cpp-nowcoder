#include <iostream>

using namespace std;

int get_first_even(int n) {
    int yht[n][7];
    yht[0][0] = 1;
    yht[1][0] = 1; yht[1][1] = 1; yht[1][2] = 1; 
    yht[2][0] = 1; yht[2][1] = 2; yht[2][2] = 3; yht[2][3] = 2; yht[2][4] = 1;
    yht[3][0] = 1; yht[3][1] = 3; yht[3][2] = 6; yht[3][3] = 7; yht[3][4] = 6;
    yht[3][5] = 3; yht[3][6] = 1; 
    for (int i=4; i<n; i++) {
        for (int j=0; j<7; j++) {
            if (j==0) yht[i][j] = 1;
            else if (j==1) yht[i][j] = yht[i-1][0] + yht[i-1][1];
            else yht[i][j] = yht[i-1][j-2] + yht[i-1][j-1] + yht[i-1][j];
        }
    }
    int fe = -1;
    for (int j=0; j<7; j++) {
        if (yht[n-1][j]%2==0) {
            fe = j+1;
            break;
        }
    }
    return fe;
}

int main() {
    int n;
    int fe, fe_;
    /*
    while (cin>>n) {
        if (n<=2) cout << -1 << ' ' << get_first_even(n) << endl;
        else if (n%2) cout << 2 << ' ' << get_first_even(n) << endl;
        else if (n%4==0) cout << "3 " << get_first_even(n) << endl;
        else cout << "4 " << get_first_even(n) << endl;
    }
    */
    for (int n=4; n<1000000; n++) {
        if (n%2) {if (get_first_even(n)!=2) cout << "2 " << get_first_even(n) << endl; }
        else if (n%4==0) {if (get_first_even(n)!=3) cout << "3 " << get_first_even(n) << endl; }
        else {if (get_first_even(n)!=4) cout << "4 " << get_first_even(n) << endl;}

        if (n%1000==0) cout << n << endl;
    }  
    return 0;
}