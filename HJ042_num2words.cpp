#include <string>
#include <iostream>

using namespace std;

string int2str1(int res) {
    switch(res) {
        case 0: return "";
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
    }
}

string int2str2(int res) {
    string rst_ = "";
    if (res<10) return int2str1(res);
    else if (res<20) {
        switch(res) {
            case 10: return "ten";
            case 11: return "eleven";
            case 12: return "twelve";
            case 13: return "thirteen";
            case 14: return "fourteen";
            case 15: return "fifteen";
            case 16: return "sixteen";
            case 17: return "seventeen";
            case 18: return "eighteen";
            case 19: return "nineteen";
        }
    } else {
        if (res<30) return "twenty "+int2str1(res-20);
        else if (res<40) return "thirty " + int2str1(res-30);
        else if (res<50) return "forty " + int2str1(res-40);
        else if (res<60) return "fifty " + int2str1(res-50);
        else if (res<70) return "sixty " + int2str1(res-60);
        else if (res<80) return "seventy " + int2str1(res-70);
        else if (res<90) return "eighty " + int2str1(res-80);
        else return "ninety " + int2str1(res-90);
    }
}

string int2str3(int res) {
    if (res<100) return int2str2(res);
    else if (res==100) return "one hundred";
    else return int2str1(res/100) + " hundred and " + int2str2(res%100);
}

class Solution {
    string trimmer(string str) {
        while (str[str.length() - 1] == ' ') str.erase(str.end() - 1);
        return str;
    }
    
    string int2str1(int res) {
        switch(res) {
            case 0: return "";
            case 1: return "one";
            case 2: return "two";
            case 3: return "three";
            case 4: return "four";
            case 5: return "five";
            case 6: return "six";
            case 7: return "seven";
            case 8: return "eight";
            case 9: return "nine";
        }
        return "";
    }
    
    string int2str2(int res) {
        string rst_ = "";
        if (res<10) return int2str1(res);
        else if (res<20) {
            switch(res) {
                case 10: return "ten";
                case 11: return "eleven";
                case 12: return "twelve";
                case 13: return "thirteen";
                case 14: return "fourteen";
                case 15: return "fifteen";
                case 16: return "sixteen";
                case 17: return "seventeen";
                case 18: return "eighteen";
                case 19: return "nineteen";
            }
        } else {
            if (res<30) rst_ = "twenty "+int2str1(res-20);
            else if (res<40) rst_ = "thirty " + int2str1(res-30);
            else if (res<50) rst_ = "forty " + int2str1(res-40);
            else if (res<60) rst_ = "fifty " + int2str1(res-50);
            else if (res<70) rst_ = "sixty " + int2str1(res-60);
            else if (res<80) rst_ = "seventy " + int2str1(res-70);
            else if (res<90) rst_ = "eighty " + int2str1(res-80);
            else rst_ = "ninety " + int2str1(res-90);
        }
        return trimmer(rst_);
    }
    
    string int2str3(int res) {
        if (res<100) return int2str2(res);
        else if (res%100==0) return trimmer(int2str1(res/100) + " hundred");
        else return trimmer(int2str1(res/100) + " hundred and " + int2str2(res%100));
    }
    
public:
    string numberToWords(int n) {
        if (n==0) return "zero";
        int res, cnt;
        string rst = "";
        cnt = 0;
        while (n>0) {
            res = n%1000;
            if (cnt==0) rst += int2str3(res);
            else if (cnt==1 and res>0) rst = int2str3(res) + " thousand " + rst;
            else if (cnt==2 and res>0) rst = int2str3(res) + " million " + rst;
            else if (cnt==3) rst = int2str3(res) + " billion " + rst;
            n /= 1000;
            cnt++;
        }
        
        return trimmer(rst);
    }
};


int main() {
    long n;
    int res, cnt;
    string rst;
    while (cin >> n) {
        rst = "";
        cnt = 0;
        if (n<0 or n>999999999) rst = "error";
        else rst = Solution().numberToWords(n);
        /*
        else {
            while (n>0) {
                res = n%1000;
                if (cnt==0) rst += int2str3(res);
                else if (cnt==1) {
                    if (rst.length()==0) rst = rst = int2str3(res) + " thousand";
                    else if (res>0) rst = int2str3(res) + " thousand " + rst;
                }
                else if (cnt==2) {
                    if (rst.length()==0) rst = int2str3(res) + " million";
                    else if (res>0) rst = int2str3(res) + " million " + rst;
                }
                else if (cnt==3) rst = int2str3(res) + " billion " + rst;
                n /= 1000;
                cnt++;
            }
        }
        */
        
        cout << rst << endl;
    }
    return 0;
}