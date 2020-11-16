#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int my_stoi(string str) {
    if (str.length()==0) return -1;
    for (char c: str) {
        if (c<48 or c>57) return -1;
    }
    return stoi(str);
}

int validate_ip(string ip_str) {
    int ip[4] = {0};
    stringstream ss(ip_str);
    string ip_part_str;
    int ip_part_int;
    for (int i=0; i<4; i++) {
        if (ss.good()) {
            getline(ss, ip_part_str, '.');
            ip_part_int = my_stoi(ip_part_str);
            if (ip_part_int<0 or ip_part_int>255) return -1;
            else ip[i] = ip_part_int;
        } else return -1;
    }
    if (ip[0]==0 or ip[0]==127) return 0;
    else if (ip[0]>=1 and ip[0]<=9) return 1;
    else if (ip[0]==10) return 6;
    else if (ip[0]>=11 and ip[0]<=126) return 1;
    else if (ip[0]>=128 and ip[0]<=171) return 2;
    else if (ip[0]==172) {
        if (ip[1]<16 or ip[1]>31) return 2;
        else return 7;
    }
    else if (ip[0]>=173 and ip[0]<=191) return 2;
    else if (ip[0]==192) {
        if (ip[1]==168) return 8;
        else return 3;
    }
    else if (ip[0]>192 and ip[0]<=223) return 3;
    else if (ip[0]>=224 and ip[0]<=239) return 4;
    else if (ip[0]>=240 and ip[0]<=255) return 5;
}

int validate_mask(string mask_str) {
    int mask[4] = {0};
    stringstream ss(mask_str);
    string mask_part_str;
    int mask_part_int;
    for (int i=0; i<4; i++) {
        if (ss.good()) {
            getline(ss, mask_part_str, '.');
            mask_part_int = my_stoi(mask_part_str);
            if (mask_part_int<0 or mask_part_int>255) return -1;
            else mask[i] = mask_part_int;
        } else return -1;
    }

    if (mask[0]==255 and mask[1]==255 and mask[2]==255 and mask[3]==255) return -1;
    else if (mask[0]==0 and mask[1]==0 and mask[2]==0 and mask[3]==0) return -1;
    else {
        int vmask[4] = {0};
        int vmask_all[] = {254,252,248,240,224,192,128};
        for (int i=0; i<4; i++) {
            if (mask[i]==255) vmask[i] = 2;
            else {
                for (int vmask_: vmask_all) {
                    if (mask[i]==vmask_) {
                        vmask[i] = 1;
                        break;
                    }
                }
            }
        }
        if (vmask[0]==0) return -1;
        else if ((vmask[0]==1) and (mask[1]+mask[2]+mask[3]>0)) return -1;
        else {
            if (vmask[1]==0 and (mask[1]+mask[2]+mask[3]>0)) return -1;
            else if (vmask[1]==1) {
                if (mask[2]+mask[3]>0) return -1;
                else return 1;
            } else {
                if (vmask[2]==0 and (mask[2]+mask[3]>0)) return -1;
                else if (vmask[2]==1 and mask[3]>0) return -1;
                else if (vmask[2]==2) {
                    if (vmask[3]==0 and mask[3]>0) return -1;
                    else return 1;
                }
                else return 1;
            }
        }
    }
}

int main() {
    int rst[7]={0};
    string ip_str, mask_str;
    int ip_rst, mask_rst;
    vector<string> rst_all;
    for (string line; getline(cin, line);) {
        if (line.length()==0) break;
        stringstream ss(line);
        getline(ss, ip_str, '~');
        getline(ss, mask_str, '~');
        ip_rst = validate_ip(ip_str);
        mask_rst = validate_mask(mask_str);
        if (ip_rst<0 or mask_rst<0) rst[5]+=1;
        else if (ip_rst>=1 and ip_rst<=5) rst[ip_rst-1] += 1;
        else if (ip_rst>5) {
            rst[ip_rst-6] += 1;
            rst[6] += 1;
        }
        string rst_str = "";
        for (int i=0; i<7; i++) rst_str += to_string(rst[i]) + " ";
        rst_str[rst_str.length()-1] = '\n';
        rst_all.push_back(rst_str);
    }

    for (auto rst_str: rst_all) {
        cout << rst_str;
    }
    
    string rst_str = "";
    for (int i=0; i<7; i++) rst_str += to_string(rst[i]) + " ";
    rst_str[rst_str.length()-1] = '\n';
    cout << rst_str;
    return 0;
}