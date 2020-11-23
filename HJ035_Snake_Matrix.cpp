#include <string>
#include <iostream>
using namespace std;

int main() {
    int n; 
    while(cin>>n) {
        int mat[n][n];
    
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<=i; j++) {
                cnt++;
                mat[i-j][j] = cnt;
            }
        }

        string line;
        for (int i=0; i<n; i++) {
            line = "";
            for (int j=0; j<n-i; j++) {
                line += to_string(mat[i][j]) + " "; 
            } 
            line[line.length()-1] = '\n';
            cout << line;
        }
    }
    
    
    return 0;
}