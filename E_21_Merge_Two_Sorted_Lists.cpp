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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x,ListNode* n) : val(x), next(n) {}
};
class Solution {
public:
   	static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
   		        // find the end with maximun
   		/*
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        
        if(l1->val < l2->val) {
            //l2 大 在 march l1
            l1->next = mergeTwoLists(l1->next, l2);
            cout << l1 ->val<< endl;
            return l1;
        }else {
            l2->next = mergeTwoLists(l2->next, l1);
            cout << l2 ->val<< endl;
            return l2;
        }
		*/

    	if (l1 == nullptr && l2 == nullptr) return NULL;
    	if (l1 && l2 == nullptr) return l1;
    	if (l2 && l1 == nullptr) return l2;

        ListNode* base;
        ListNode* merge;

        if (l1 -> val <= l2 -> val){
        	base = l1;
        	merge = l2;
        }
        else{
        	base = l2;
        	merge = l1;
        }  
        //ListNode* pre = new ListNode(-1,base);
        ListNode* cur = base;
        ListNode* post = base -> next;
        while (cur){
        	/*no need to consider left insert*/
        	/*
        	if (merge -> val >=  pre -> val && merge -> val <= cur -> val){
        		ListNode* temp = merge -> next;
        		pre -> next = merge;
        		merge -> next = cur;
        		cur = merge;
        		merge = temp;
        	}*/
       
        	if(post == nullptr && merge -> val >=  cur -> val){
        		cur -> next = merge;
        		return base;
        	}
        	else if (merge -> val >=  cur -> val && merge -> val <= post -> val){
        		ListNode* temp = merge -> next;
        		cur -> next = merge;
        		merge -> next = post;
        		cur = merge;
        		if (temp == nullptr) break;
        		else merge = temp;
        		post = cur -> next;
        	}else{
        		cur = cur ->next;
        		post = (cur -> next)?cur->next:nullptr;
        	}
        }
        return base;
    }
};


int main(int argc, char ** argv){
	ListNode n4(9,NULL);
	ListNode n5(7,&n4);
	ListNode n6(5,&n5);
	ListNode n7(3,&n6);
	ListNode n8(1,&n7);

	ListNode n14(10,NULL);
	ListNode n15(8,&n14);
	ListNode n16(6,&n15);
	ListNode n17(4,&n16);
	ListNode n18(2,&n17);


	ListNode* check = Solution::mergeTwoLists(&n8,&n18);
	while (check){
		cout << check -> val;
		check = check -> next;
	}


	return 0;

}