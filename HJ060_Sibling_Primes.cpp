#include <vector>
#include <iostream>

using namespace std;

bool is_prime(int k, vector<int> pm) {
    for (int p : pm) {
        if (k==p) return true;
        else if (k%p==0) return false;
    }
    return true;
}

vector<int> get_primes(int n, vector<int> pm) {
    for (int i=pm[pm.size()-1]+1; i<n; i++) {
        if (is_prime(i, pm)) pm.push_back(i);
    }
    return pm;
}

int main() {
    int n, diff, tmp;
    int rst[2];
    vector<int> pm = {2};
    while (cin>>n) {
        pm = get_primes(n, pm);
        diff = n;
        rst[1] = n;
        for (int p : pm) {
            if (p>=rst[1] or p>=n) break;
            tmp = n-p;
            if (is_prime(tmp, pm)) {
                if (tmp - p < diff) {
                    diff = tmp - p;
                    rst[0] = p;
                    rst[1] = tmp;
                }
            }
        }
        cout << rst[0] << endl;
        cout << rst[1] << endl;
    }
    
    
    return 0;
}