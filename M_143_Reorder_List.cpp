/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <stack>
#include <queue>
using namespace std;


class ListNode {
public:
	int val;
	ListNode * next;
	ListNode (int x, ListNode* n): val(x),next(n){}
};

ostream & operator << (ostream & o,  const ListNode* node){
	//ListNode* node = n;
	while(node){
		o << node -> val;
		node = node ->next;
	}
	return o <<endl;
}

class Solution {
public:
	static int isOdd(ListNode* head){
		ListNode* cur = head;
		int cout = 0;
		for(;cur; cur = cur -> next){
			cout += 1;
		}
		return (cout % 2 == 0)? 0: 1;

	}
    static void reorderList(ListNode* head) {
    //Determine if odd / even
    if (head == nullptr) return;

    ListNode* h_p = head;


    //static method can be called
    if (!isOdd(head)){
    	ListNode* dummy = new ListNode(-1,head);
        head = dummy;
    }

    ListNode* slow = head;
    ListNode* fast = head;

 
   	while(fast -> next && slow-> next && fast -> next -> next){
    	slow = slow -> next;
	 	fast = fast -> next -> next;
    }
    


    //Now that in between slow pointer and fast pointer is the things we are inserting
    
    stack<ListNode*> s;
    while(slow != fast){
    	s.push(slow -> next);
    	slow = slow -> next;
    }
 
    while(!s.empty()){
    	ListNode* temp = h_p ->next;
    	ListNode* insertion = s.top();
    	s.pop();
    	h_p -> next = insertion;
    	insertion -> next = temp;
    	h_p = temp;
    }
    h_p -> next = nullptr;
    //return head;
    
        
    }
};

int main(int argc, char ** argv){
	ListNode n1(5,NULL);
	ListNode n2(4,&n1);
	ListNode n3(3,&n2);
	ListNode n4(2,&n3);
	//ListNode n5(1,&n4);

	cout << Solution::isOdd(&n4);
	cout << &n4 << endl;
	Solution::reorderList(&n4);
	cout << &n4 << endl;

	return 0;
}