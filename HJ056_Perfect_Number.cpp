#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_perfect(int k) {
    vector<int> factor = {1};
    for (int i=2; i<(int)(sqrt(k)+1); i++) {
        if (k%i==0) {
            factor.push_back(i);
            factor.push_back(k/i);
        }
    }
    int sum = 0;
    for (int i=0; i<factor.size(); i++) sum += factor[i];
    if (sum==k) return true;
    else return false;
}

int perfect_numbers(int n) {
    int cnt = 0;
    for (int i = 6; i<=n; i++) {
        if (is_perfect(i)) cnt++;
    }
    return cnt;
}

int main() {
    int n;
    while (cin >> n) {
        cout << perfect_numbers(n) << endl;
    }
    return 0;
}