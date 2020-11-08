#include <iostream>

using namespace std;

struct ListNode {
    int key, val;
    ListNode *Next;
    ListNode(int key_, int val_): key(key_), val(val_), Next(NULL) {};
};

int main() {
    int n; cin >> n;
    ListNode *pHead=NULL, *pTmp, *pLoc, *pLocPrev;

    int key, val;
    for (int i=0; i<n; i++) {
        pLocPrev = pHead;
        cin >> key >> val;
        pTmp = new ListNode(key, val);

        if (pHead==NULL) pHead = pTmp; 
        else if (pTmp->key < pHead->key) {
            pTmp->Next = pHead;
            pHead = pTmp;
        } else if (pTmp->key == pHead->key) {
            pHead->val += pTmp->val;
        } else {
            if (pHead->Next==NULL) pHead->Next = pTmp;
            else {
                pLoc = pHead->Next;
                while (pLoc!=NULL) {
                    if (pTmp->key < pLoc->key) {
                        pTmp->Next = pLoc;
                        pLocPrev->Next = pTmp;
                        break;
                    } else if (pTmp->key == pLoc->key) {
                        pLoc->val += pTmp->val;
                        break;
                    } else {
                        pLocPrev = pLoc;
                        pLoc = pLoc->Next;
                    }
                }
                if (pLoc==NULL) pLocPrev->Next = pTmp;
            }
        }
    }

    pLoc = pHead;
    while (pLoc!=NULL) {
        cout << pLoc->key << ' ' << pLoc->val << endl;
        pLoc = pLoc->Next;
    }

    return 0;
}