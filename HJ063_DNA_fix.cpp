#include <string>
#include <iostream>

using namespace std;

int main() {
    string dna;
    int len, rst_start;
    double max_rt, gc_rt, gc_cnt;

    while (cin >> dna >> len) {
        max_rt = 0.;        
        for (int i=0; i<=dna.length()-len; i++) {
            gc_cnt = 0.;
            for (int j=i; j<i+len; j++) {
                if (dna[j]=='G' or dna[j]=='C') gc_cnt += 1.;
            }
            gc_rt = gc_cnt/len;
            if (gc_rt>max_rt) {
                max_rt = gc_rt;
                rst_start = i;
            }
        }
        if (max_rt>0.) cout << dna.substr(rst_start, len) << endl;
        else cout << "NONE" << endl;
    }


    return 0;
}