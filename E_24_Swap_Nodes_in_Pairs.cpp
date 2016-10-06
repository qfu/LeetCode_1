/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std; 

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x, ListNode* n):val(x),next(n) {}
};


class Solution {
public:
    static ListNode* swapPairs(ListNode* head) {
    	if(head == nullptr) return NULL;

    	ListNode* cur = head;
    	ListNode* returnNode = cur->next;

    	ListNode* mid = cur;
    	ListNode* post = cur -> next;
    	ListNode* pre = new ListNode(-1,cur);

    	// Pointer
    	while(mid && post){
    		ListNode* temp = post -> next;
    		mid -> next = temp;
    		post -> next = mid;
    		pre -> next = post;
    		pre = mid;
    		mid = temp;
    		if (temp == nullptr) break;
    		else post = temp -> next;
    	}
    	return returnNode;
    }
};

int main(int argc, char ** argv){
	ListNode n2(7,NULL);
	ListNode n3(6,&n2);
	ListNode n4(5,&n3);
	ListNode n5(4,&n4);
	ListNode n6(3,&n5);
	ListNode n7(2,&n6);
	ListNode n8(1,&n7);

	ListNode* check = Solution::swapPairs(&n8);
	while (check){
		cout << check -> val;
		check = check -> next;
	}

	return 0;
}