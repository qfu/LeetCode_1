/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class ListNode{
public:
	int val;
	ListNode* next;
	ListNode(int x, ListNode* n): val(x),next(n){}
};

class Solution {
public:
	int getLength(ListNode* n){
		int count = 0;
		while(n){
			n = n -> next;
			count++;
		}
		return count;
	}

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if(!headA && !headB) return nullptr;
    	if (headA == headB) return headA;


    	ListNode* p1 = headA;
    	ListNode* p2 = headB;

    	int a_s = getLength(headA);
    	int b_s = getLength(headB);
    	int wait = a_s - b_s;


    	if (wait > 0){
    		while(wait--) p1 = p1->next;
    	}
    	else if (wait < 0){
    		wait = -wait;
    		while(wait--) p2 = p2->next;

    	}

    	while(p1 && p2){
    		if (p1 ==p2) return p1;
    		else{
    			p1 = p1 ->next;
    			p2 = p2 ->next;
    		}
    	}

    	return nullptr;
    }
};

int main(){

	return 0;
}