/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <unordered_set>
using namespace std;
class ListNode{
public:
	int val;
	ListNode* next;
	ListNode(int x, ListNode* n): val(x),next(n){}
};

/*
ostream & operator<< (ostream & o , const ListNode* l){
	while(l){
		o << l -> val;
		if (l -> next)l = l -> next;
		else break;
	}
	return o << endl;
}
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	//Edge cast 
    	if (head == nullptr) return nullptr;
    	if (!(head->next)) return head;

    	unordered_set<int> set;
    	ListNode* head_r = head;
    	ListNode* cur = head;
    	ListNode* pre = new ListNode(-1,cur);
    	//ListNode* dummy = new ListNode(-1,cur);
    	ListNode* end = cur -> next;

    	while(cur){
    		if (cur -> next){
	    		if (cur -> val == cur ->next -> val){
	    			set.insert(cur -> val);
	    		}
	    	}
    		if (cur -> next) cur = cur -> next;
    	}

    	for(;head_r;){
    		if(set.find(head_r->val) != set.end()){
    			pre -> next = end;
    			head_r = end;
    			end = (end -> next == nullptr)? nullptr:end;
    		}

    		else if (head_r -> next){
    			pre = pre -> next;
    		 	head_r = head_r -> next;
    			end = (end -> next == nullptr)? nullptr:end;

    		}
    	}

    	return head;
    }
};


int main(int argc, char ** argv){
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.
	ListNode n1(5,NULL);
	ListNode n2(4,&n1);
	ListNode n3(3,&n2);
	ListNode n4(3,&n3);
	ListNode n5(2,&n4);
	ListNode n6(1,&n5);
	ListNode n7(1,&n6);
	ListNode n8(1,&n7);


	Solution solver;
	//cout << &n6;

	//cout << 
	solver.deleteDuplicates(&n8);

}