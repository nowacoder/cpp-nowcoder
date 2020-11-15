#include <vector>
#include <iostream>

using namespace std;

int next_prime(vector<int> prime_list) {
    int tmp = *(prime_list.end()-1);
    bool flag = false;
    while (!flag) {
        tmp += 2;
        flag = true;
        for (int t: prime_list) {
            if (tmp%t==0)  {
                flag = false;
                break;
            }
        }
    }
    return tmp;
}

int main() {
    int n; cin >> n;
    vector<int> rst;
    
    int prime = 2;
    while (n%prime==0) {
        rst.push_back(prime);
        n /= 2;
    }

    prime = 3;
    vector<int> prime_list{prime};
    while (n>=prime) {
        while (n%prime==0) {
            rst.push_back(prime);
            n /= prime;
        }
        prime = next_prime(prime_list);
        prime_list.push_back(prime);
    }

    for (int t: rst) cout << t << endl;

    return 0;
}