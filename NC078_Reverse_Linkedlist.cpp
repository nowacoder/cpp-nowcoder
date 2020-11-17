
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead==NULL) return pHead;
        if (pHead->next==NULL) return pHead;
        else {
            ListNode *newHead, *tmp;
            newHead = new ListNode(pHead->val);
            pHead = pHead->next;
            while(pHead != NULL) {
                tmp = new ListNode(pHead->val);
                tmp->next = newHead;
                newHead = tmp;
                pHead = pHead->next;
            }
            return newHead;
        }
    }
};

int main() {
    ListNode *pHead, *tmp, *tail;
    tail = new ListNode(1); 
    pHead = tail;
    for (int i=0; i<3; i++) {
        tmp = new ListNode(i);
        tail->next = tmp;
        tail = tmp;
    }

    ListNode *rst = Solution().ReverseList(pHead);

    return 0;
}
