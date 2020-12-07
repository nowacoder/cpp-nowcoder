#include <vector>
#include <chrono>
#include <iostream>

using namespace std;

vector<int> get_primes() {
    vector<int> primes = {2, 3, 5, 7, 11, 13};
    int flag;
    for (int i=17; i<59999; i++) {
        flag = true;
        for (int p : primes) {
            if (i%p==0) {
                flag = false;
                break;
            } 
        }
        if (flag) primes.push_back(i);
    }
    return primes;
}

int prime_mates(vector<int> nums, bool primes_vec[]) {
    if (nums.size()==2) {
        if (primes_vec[nums[0]+nums[1]]) return 1;
        else return 0;
    } else {
        int max_mates = 0, mates;
        for (int i=1; i<nums.size(); i++) {
            vector<int> res_nums;
            for (int j=1; j<nums.size(); j++) {
                if (i!=j) res_nums.push_back(nums[j]);
            }
            mates = prime_mates(res_nums, primes_vec);
            if (primes_vec[nums[0]+nums[i]]) mates++;
            if (mates>max_mates) max_mates = mates;
        }
        return mates;
    }
}

int main() {
    vector<int> primes = get_primes();
    bool primes_vec[primes[primes.size()-1]+1];
    for (int i=0; i<primes[primes.size()-1]+1; i++) {
        primes_vec[i] = false;
    }
    //{
        // if (i%10000==0) cout << i << endl;
        //primes_vec[i] = false;
    //}
    for (int p : primes) primes_vec[p] = true;
    
    int n, num;
    while (cin>>n) {
        vector<int> nums;
        for (int i=0; i<n; i++) {
            // cin >> num;
            nums.push_back(i+5);
        }
        chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        cout << prime_mates(nums, primes_vec) << endl;
        chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    }
    return 0;
}