#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct GC_Seg {
    int start, end;
    double len;
    GC_Seg(int s_, int e_, double l_): start(s_), end(e_), len(l_) {}
};

string  get_gch(string dna, int len) {
    int s_, e_;
    double l_;
    vector<GC_Seg> gcs;
    for (int i=0; i<dna.length(); i++) {
        if (dna[i]=='G' or dna[i]=='C') {
            s_ = i;
            while ((dna[i]=='G' or dna[i]=='C') and i<dna.length()) i++;
            e_ = i-1;
            l_ = i-s_;
            if (l_>=len) return dna.substr(s_, l_);
            GC_Seg gc = GC_Seg(s_, e_, l_);
            gcs.push_back(gc);
        }
    }
    int seg_start, seg_end, seg_len;
    double gc_cnt, gcr, max_gcr = 0.; // make sure max_gcr is initialized
    int max_gcr_start, max_gcr_end;
    for (int i=0; i<gcs.size()-1; i++) {
        GC_Seg gc1 = gcs[i];
        seg_start = gc1.start;
        gc_cnt = gc1.len;
        for (int j=i+1; j<gcs.size(); j++) {
            GC_Seg gc2 = gcs[j];
            seg_end = gc2.end;
            seg_len = seg_end - seg_start + 1;
            gc_cnt += gc2.len;
            gcr = gc_cnt / seg_len;
            if (gcr>max_gcr and seg_len>=len) {
                max_gcr = gcr;
                max_gcr_start = seg_start;
                max_gcr_end = seg_end;
            }
        }
    }

    if (max_gcr>0.) {
        return dna.substr(max_gcr_start, max_gcr_end-max_gcr_start+1);
    }
    else return NULL;
}

int main() {
    string dna; 
    int len_;
    while (cin >> dna) {
    // for (string dna; getline(cin, dna);) {
        cin >> len_;
        cout << get_gch(dna, len_) << endl;
    }
    return 0;
}