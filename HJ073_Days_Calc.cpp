#include <iostream>

using namespace std;

int cal_days(int y, int m, int d) {
    int md[12] = {31, 28, 31, 30, 31, 30, 
                  31, 31, 30, 31, 30, 31};
    if (y%100==0) {
        if (y%400==0) md[1] = 29;
    } else if (y%4==0) md[1] = 29;
    else if (y<0) return -1;
    
    if (m<=0 or m>12) return -1;
    if (d<=0 or d>md[m-1]) return -1;
    
    int rst = 0;
    for (int i=0; i<m-1; i++) rst += md[i];
    return rst+d;
}

int main() {
    int y, m, d, n;
    while (cin >> y >> m >> d) {
        n = cal_days(y, m, d);
        cout << n << endl;
    }
    return 0;
}