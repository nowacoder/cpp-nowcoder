#include <iostream>

using namespace std;

double tri(double tmp) {
    return tmp*tmp*tmp;
}

int main() {
    double in, left, right, mdl, mdl3;
    bool flag;
    while (cin>>in) {
        if (in<0) {
            flag = true;
            in *= -1;
        } else flag = false;
        if (in<1) {
            left = in;
            right = 1;
        } else {
            left = 1;
            right = in;
        }
        mdl = (left+right)/2;
        mdl3 = tri(mdl);
        while ((mdl3-in)*(mdl3-in)>0.0001) {
            if (mdl3>in) right = mdl;
            else left = mdl;
            mdl = (left+right)/2;
            mdl3 = tri(mdl);
        }
        if (flag) mdl *= -1;
        printf("%.1f\n", mdl);
    }
    return 0;
}