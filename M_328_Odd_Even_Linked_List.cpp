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


class ListNode{
public:
	int val;
	ListNode* next;
	ListNode(int x, ListNode* n) :val(x),next(n){}
};


ostream & operator << (ostream & o, ListNode* n){
	while(n){
		o << n->val;
		n = n -> next;
	}
	return o << endl;
}
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if (!head) return nullptr;
        if (!head -> next) return head;

        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* evenH = even;
        while(odd && even && even -> next){
            odd -> next = even -> next;
            odd = odd -> next;
            even -> next = odd ->next;
            even = even -> next;
            odd ->next = nullptr;
        }
        odd -> next = evenH;
        return head;
    }
};


int main(int argc, char ** argv){
	
	//ListNode n1(8,NULL);
	ListNode n2(7,NULL);
	ListNode n3(6,&n2);
	ListNode n4(5,&n3);
	
	ListNode n5(4,&n4);
	ListNode n6(3,&n5);
	ListNode n7(2,&n6);
	ListNode n8(1,&n7);

	Solution s;
	cout << s.oddEvenList(&n8);


}