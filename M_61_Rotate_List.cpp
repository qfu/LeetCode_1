#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x, ListNode* n) : val(x), next(n) {}
};
class Solution {
public:
	int listSize(const ListNode* head){
		const ListNode* cur = head;
		int cout = 0;
		while(cur){
			cur = cur -> next;
			cout += 1;
		}
		return cout;
	}


    ListNode* rotateRight(ListNode* head, int k) {
    	if (head == nullptr) return nullptr;
    	int size = listSize(head);
    	int rotate = k % size;

    	if (rotate == 0) return head;

    	int remain = size - rotate;
    	ListNode* cur = head;
    	while(cur && --remain){
    		cur = cur -> next;
    	}

    	ListNode* newHead = cur -> next;
    	ListNode* loop = newHead;
    	cur -> next = nullptr;

    	while(loop->next){
    		loop = loop ->next;
    	}
    	loop -> next = head;
    	return newHead;
        
    }
};

int main(int argc, char ** argv){
	ListNode n7(3,NULL);
	ListNode n8(4,&n7);


	Solution s;
	ListNode* check = s.rotateRight(&n8,1);
	while(check){
		cout << check -> val;
		check = check -> next;
	}
	return 0;

}