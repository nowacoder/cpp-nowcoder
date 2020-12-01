#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int _val): val(_val) {};
};

int main() {
    int n, v, k;
    while (cin>>n) {
        ListNode *pHead, *pTail, *pTmp;
        cin >> v;
        pTmp = new ListNode(v);
        pHead = pTmp; pTail = pTmp;
        for (int i=1; i<n; i++) {
            cin >> v;
            pTmp = new ListNode(v);
            pTmp->next = pTail;
            pTail = pTmp;
        }
        cin >> k;
        if (k==0) cout << 0 << endl;
        else {
            pTmp = pTail;
            for (int i=1; i<k; i++) {
                pTmp = pTmp->next;
            }
            cout << pTmp->val << endl;
        }
    }
    return 0;
}