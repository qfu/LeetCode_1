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
	ListNode(int x, ListNode* n): val(x),next(n){}
};
ostream & operator << (ostream & o, ListNode* n){
	while(n){
		o << n ->val;
		n = n -> next;
	}
	return o << endl;
}

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        if (head -> next == nullptr) return head;
        //Return Node 
        ListNode* returnNode = new ListNode(-1,head);
        //Iterate to find first node
        ListNode* cur = head;
        int index = 0;
        ListNode* dummy = new ListNode(-1,cur);
        while(cur->next){
        	if (cur -> val >= x){
        		break;
        	}
        	index += 1;
        	dummy = dummy -> next;
        	cur = cur -> next;
        }

        //if (index == 0){
        returnNode = dummy;
        //}
  
        //cout << "first Node" <<cur -> val << endl;
        ListNode* less = head;
        ListNode* lessPrev = new ListNode(-1,less);
        int second  = 0;
        while(less){
        	if (less -> val < x && second > index){
        		//perform insertin
        		ListNode* temp = less -> next;
        		lessPrev -> next = temp;
        		dummy -> next = less;
        		less -> next = cur;
        		//before update less;
        		dummy = less;
        		less = temp;
        		continue;
        	}
        	//Update has problem
        	second += 1;
        	less = less -> next;
        	lessPrev = lessPrev -> next;
        }
        cout << returnNode -> val;

        return returnNode -> next;
    }
};


int main(int argc, char ** argv){

/*
	ListNode n1(5,NULL);
	ListNode n2(4,&n1);
	ListNode n3(9,&n2);
*/
//	ListNode n4(1,NULL);
//	ListNode n5(2,&n4);

	ListNode n6(2,NULL);
	ListNode n7(3,&n6);
	ListNode n8(4,&n7);

	Solution s;
	ListNode* check = s.partition(&n8,4);
	while(check){
		cout << check -> val;
		check = check -> next;
	}

}