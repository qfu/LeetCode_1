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
	ListNode(int v, ListNode* n): val(v),next(n){}
};

ostream & operator << (ostream & o ,  const ListNode* cur){
	//ListNode* cur = n;
	while(cur){
		o << cur -> val;
		cur = cur -> next;
	}
	return o << endl;
}


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if (head==nullptr || head -> next == nullptr) return head;

    	ListNode* pre = head;
    	ListNode* mid = head -> next;

    	while(mid){
    		ListNode* post = mid -> next;
    		head -> next = post;
    		mid -> next = pre;
    		pre = mid;
    		mid = post;
    	}

        return pre;
    }
};

int main(int argc, char ** argv){
	ListNode n1(5,NULL);
	ListNode n2(4,&n1);
	ListNode n3(3,&n2);
	ListNode n4(2,&n3);
	ListNode n5(1,&n4);

	Solution solver;
	cout << solver.reverseList(&n5);
	//cout << &n5;
}