#include <vector>
#include <iostream>

using namespace std;

int main() {
    long in; cin >> in;
    vector<long> vec;
    long pst;
    while(in>0) {
        pst = in%10;
        in = in/10;
        if (vec.size()==0) vec.push_back(pst);
        else {
            for (int i=0; i<vec.size(); i++) {
                if (pst==vec[i]) break;
                else if (i==vec.size()-1) vec.push_back(pst);
            }
        }
    }
    long out=0;
    for (int i=0; i<vec.size(); i++) out = out*10+vec[i];
    cout << out << endl;
    
    return 0;
}