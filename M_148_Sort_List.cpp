#include <iostream>
using namespace std;


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
	ListNode(int x, ListNode* n):val(x),next(n){}
};

ostream & operator<< (ostream & o , const ListNode* l){
	while(l){
		o << l -> val;
		if (l -> next)l = l -> next;
		else break;
	}
	return o << endl;
}

class Solution {
public:



   ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast =head->next;
         while(fast && fast->next){         // to find middle node     
            fast= fast->next->next;
            slow = slow->next;
        }
        ListNode* headb = slow->next;     // headb is start of 2nd half of list
        slow->next = NULL;                 
        return mergeSort(sortList(head) , sortList(headb));
        }

	ListNode* mergeSort(ListNode* l1, ListNode* l2){
        ListNode* d = new ListNode (-1,NULL);            // dummy node
        ListNode* e = d;
        while(l1||l2){
            if(l1 && (!l2 || l1->val <= l2 -> val) ){
                e=e->next = l1 ; 
               	l1 = l1 -> next;
            }
            if(l2 && (!l1 || l2->val < l1 -> val) ){
                e=e->next= l2 ; 
                l2 = l2 -> next;
            }
        }
        e->next = NULL;
        return d->next;
	}






    ListNode* sortList_second_Pointer(ListNode* head) {
       if(!head || !(head->next)) return head;

       	ListNode* front = new ListNode(-1,head);
       	ListNode* cur = head;
       	ListNode* pre = front;
       	ListNode* end  = head -> next -> next;
		ListNode** iter = &(head -> next->next);       	
       	while((*iter)->next){


       		//save the node
       		ListNode* insert = *iter;
       		cout << "insert" << insert ->val << endl;


       		ListNode* next  = insert -> next;
       		cout << "next" << next ->val << endl;

       		//iter = &((*iter)->next);

         	cout << "the before list" << pre-> next << endl;
       		*iter = (*iter)->next;
         	cout << "the after list" << pre-> next << endl;


       			//delete iter node
       			while(cur){
       				
       				if (insert -> val <= cur -> val){
       					front -> next = insert;
       					insert -> next = cur;
       					end = cur;
       					front = pre;
       					cur = front->next;
       					break;
       				}
       				else{
       					cur = cur -> next;
       					front = front -> next;
       				}
       			}
            cout << "the list" << pre-> next << endl;
       		//don't save the address
       		//otherwise deference will cause errors
       		//the effect is not
       		*iter = next;
       		cout << "the list" << pre-> next << endl;
       	}
       	return pre->next;
    }








};


int main(){
	ListNode n1(9,NULL);
	ListNode n2(7,&n1);
	ListNode n3(2,&n2);
	ListNode n4(5,&n3);
	ListNode n5(2,&n4);
	ListNode n6(3,&n5);
	ListNode n7(1,&n6);
	ListNode n8(4,&n7);


	cout << &n8;
	Solution solver;
	cout << solver.sortList_second_Pointer(&n8);


}
