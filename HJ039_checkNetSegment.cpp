#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
    string mask_str, ip1_str, ip2_str, tmp_str;
    int mask[4], ip1[4], ip2[4], rst, tmp;
    bool mask_[32], ip1_[32], ip2_[32];
    
    while (cin >> mask_str) {
        rst = 0;
        
        cin >> ip1_str;
        cin >> ip2_str;
        
        stringstream mask_ss(mask_str);
        stringstream ip1_ss(ip1_str);
        stringstream ip2_ss(ip2_str);
        for (int i=0; i<4; i++) {
            if (mask_ss.good()) {
                getline(mask_ss, tmp_str, '.');
                tmp = stoi(tmp_str);
                if (tmp<0 or tmp>255) {
                    rst = 1;
                    break;
                }
                else {
                    mask[i] = tmp;
                    for (int j=7; j>=0; j--) {
                        mask_[i*8+j] = tmp%2;
                        tmp /= 2;
                    }
                }
            }
            if (ip1_ss.good()) {
                getline(ip1_ss, tmp_str, '.');
                tmp = stoi(tmp_str);
                if (tmp<0 or tmp>255) {
                    rst = 1;
                    break;
                }
                else {
                    ip1[i] = tmp;
                    for (int j=7; j>=0; j--) {
                        ip1_[i*8+j] = tmp%2;
                        tmp /= 2;
                    }
                }
            }
            if (ip2_ss.good()) {
                getline(ip2_ss, tmp_str, '.');
                tmp = stoi(tmp_str);
                if (tmp<0 or tmp>255) {
                    rst = 1;
                    break;
                }
                else {
                    ip2[i] = tmp;
                    for (int j=7; j>=0; j--) {
                        ip2_[i*8+j] = tmp%2;
                        tmp /= 2;
                    }
                }
            }
        }

        
        if (rst==0) {
            for (int i=0; i<32; i++) {
                if (i>0 and mask_[i]>mask_[i-1]) {
                    rst = 1;
                    break;
                }
            }
            
            for (int i=0; i<32; i++) {
                ip1_[i] = mask_[i] & ip1_[i];
                ip2_[i] = mask_[i] & ip2_[i];
                if (ip1_[i]!=ip2_[i]) {
                    rst = 2;
                    break;
                }
            }
        }
        cout << rst << endl;
        
    }
    
    return 0;
}