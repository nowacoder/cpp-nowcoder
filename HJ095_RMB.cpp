#include <string>
#include <iostream>

using namespace std;

string d1(int y) {
    switch (y) {
        case 1: return "壹";
        case 2: return "贰";
        case 3: return "叁";
        case 4: return "肆";
        case 5: return "伍";
        case 6: return "陆";
        case 7: return "柒";
        case 8: return "捌";
        case 9: return "玖";
    }
    return "";
}

string d4(int y4) {
    if (y4==0) return "";
    string q="", b="", s="", g="";
    if (y4>=1000) {
        q = d1(y4/1000) + "仟";
        y4 %= 1000;
    } 
    if (y4>=100) {
        b = d1(y4/100) + "佰";
        y4 %= 100;
    }
    if (y4>=20) {
        s = d1(y4/10) + "拾";
        y4 %= 10;
    } else if (y4>=10) {
        s = "拾";
        y4 %= 10;
    }
    if (y4>0) g = d1(y4);
    
    if (b.length()>0) {
        if (s.length()>0) 
            return q+b+s+g;
        else {
            if (g.length()>0) 
                return q + b + "零" + g;
            else
                return q + b;
        }
    } else {
        if (q.length()>0) {
            if (s.length()+g.length()>0)
                return q + "零" + s + g;
            else return q;
        } else
            return s + g;
    }
}

string d0(int jf) {
    if (jf==0) return "整";
    else {
        string r0 = "";
        if (jf>=10) {
            r0 += d1(jf/10) + "角";
            jf %= 10;
        }
        if (jf>0)
            r0 += d1(jf) + "分";
        return r0;
    }
}

string RMB(int in, int jf) {
    string rmb = "人民币";
    if (in==0)
        return rmb + d0(jf);
    if (in>100000000) {
        rmb += d4(in/100000000) + "亿";
        in %= 100000000;
    }
    if (in>10000) {
        rmb += d4(in/10000) + "万";
        in %= 10000;
    }
    if (rmb.length()>9 and in>0 and in<1000)
        rmb += "零";
    return rmb + d4(in) + "元" + d0(jf);
}

int main() {
    string str, ins, jfs;
    bool flag;
    long in;
    int jf;
    while (cin >> str) {
        ins = ""; jfs = "";
        flag = false;
        for (char c : str) {
            if (c=='.') {
                flag = true;
            } else if (!flag) ins += c;
            else jfs += c;
        }
        in = stol(ins);
        jf = stoi(jfs);
        cout << RMB(in, jf) << endl;
    }
}