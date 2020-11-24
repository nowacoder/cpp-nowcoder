#include <string>
#include <bitset>
#include <sstream>
#include <iostream>
using namespace std;

int main() {
    string ip_str;
    long ip_dec;
    string ip_str_bin;
    string tmp_str;
    int tmp;
    while (cin >> ip_str >> ip_dec) {
        // cin >> ip_dec; // don't know why cin separately won't work
        if (ip_str.length()==0) break;
        ip_str_bin = "";
        stringstream ss(ip_str);
        for (int i=0; i<4; i++) {
            getline(ss, tmp_str, '.');
            ip_str_bin += bitset<8>(stoi(tmp_str)).to_string();
        }
        cout << bitset<32>(ip_str_bin).to_ulong() << endl;
        
        ip_str_bin = bitset<32>(ip_dec).to_string();
        ip_str = "";
        for (int i=0; i<4; i++) {
            tmp_str = ip_str_bin.substr(i*8,8);
            tmp = (int)(bitset<8>(tmp_str).to_ulong());
            ip_str += to_string(tmp)+'.';
        }
        ip_str[ip_str.length()-1] = '\n';
        cout << ip_str;
    }
    
    return 0;
}