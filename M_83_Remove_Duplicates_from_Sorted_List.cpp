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
 	ListNode(int x,ListNode* n) : val(x),next(n){

 	}
 };


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode* currentNode = head;
    	ListNode* original = head;

    	for(;currentNode-> next;){
    		if (! (currentNode -> val ^ currentNode -> next -> val)){
    				currentNode -> next = currentNode -> next -> next;
    		}
    		currentNode = currentNode -> next;
    	}

        return original;
    }
};

int main(int argc, char ** argv){
	ListNode n1(3,NULL);
	ListNode n2(2,&n1);
	ListNode n3(2,&n2);
	ListNode n4(1,&n3);
	ListNode n5(1,&n4);

	Solution solver;

	ListNode* check = solver.deleteDuplicates(&n5);

	do{
		cout << check -> val << endl;
		check = check -> next;

	}while(check);



	return 0;

}