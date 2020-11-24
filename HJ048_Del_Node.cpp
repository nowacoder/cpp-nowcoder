#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next=NULL;
    ListNode(int val_): val(val_) {};
};

int main() {
    int n, v0, v1, dv;
    ListNode *pHead, *pRes, *pTmp;
    while (cin>>n) {
        for (int i=0; i<n; i++) {
            if (i==0) {
                cin >> v0;
                pHead = new ListNode(v0);
            } else {
                cin >> v0 >> v1;
                if (v0==v1) continue;
                pTmp = new ListNode(v0);
                pRes = pHead;
                while (pRes->next!=NULL) {
                    if (pRes->next->val==v0) break;
                    else if (pRes->val==v1) {
                        pTmp->next = pRes->next;
                        pRes->next = pTmp;
                        break;
                    } else pRes = pRes->next;
                }
                if (pRes->next==NULL and pRes->val==v1) pRes->next = pTmp;
            }
        }
        cin >> dv;
        if (pHead->val==dv) pHead = pHead->next;
        else if (pHead->next!=NULL){
            pTmp = pHead;
            pRes = pHead->next;
            while (pRes->next != NULL) {
                if (pRes->val == dv) {
                    pTmp->next = pRes->next;
                    break;
                }
                else {
                    pTmp = pRes;
                    pRes = pRes->next;
                }
            }
        }
        while (pHead!=NULL) {
            cout << pHead->val << ' ';
            pHead = pHead->next;
        }
        cout << endl;
        
    }
    return 0;
}