#include <vector>
#include <iostream>

using namespace std;

class Finder {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        vector<int> rst;
        bool flag;
        for (int i=0; i<n; i++) {
            auto it = rst.begin();
            flag = false;
            for (int j=0; j<rst.size(); j++) {
                if (a[i]>rst[j]) {
                    rst.insert(it, a[i]);
                    flag = true;
                    break;
                } else it++;
            }
            if (!flag and rst.size()<K) rst.push_back(a[i]);
            else if (flag and rst.size()>K) rst.pop_back();
        }
        return rst[K-1];
    }
};

/*
class Finder {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        int start = 0;
        int end = n-1;
        K = n - K;
        while(1){
            int pos = find(a, start, end);
            if(pos == K){
                return a[pos];
            }else if(pos <K){
                start = pos+1;
            }else{
                end = pos - 1;
            }
        }
        return 0;
    }
     
    int find(vector<int> &arr, int left, int right){
        int pivot = arr[left];
        while(left < right){
            while(left<right && arr[right] >= pivot)
                right--;
            arr[left] = arr[right];
            while(left < right && arr[left]<= pivot)
                left++;
            arr[right] = arr[left];
        }
        arr[left] = pivot;
        return left;
    }
};
*/

int main() {
    vector<int> a{1332802,1177178,1514891,871248,753214,123866,1615405,328656,1540395,968891,
    1884022,252932,1034406,1455178,821713,486232,860175,1896237,852300,566715,1285209,1845742,
    883142,259266,520911,1844960,218188,1528217,332380,261485,1111670,16920,1249664,1199799,
    1959818,1546744,1904944,51047,1176397,190970,48715,349690,673887,1648782,1010556,1165786,937247,986578,798663};

    cout << Finder().findKth(a, 49, 24) << endl;

    return 0;
}