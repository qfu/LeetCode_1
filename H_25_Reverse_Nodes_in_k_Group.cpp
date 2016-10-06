/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <queue>
 using namespace std;

class ListNode{
public:
	int val;
	ListNode* next;
	ListNode(int x, ListNode* n): val(x),next(n){}
};

ostream & operator << (ostream & o, const ListNode* node){
	while(node){
		o << node -> val;
		node = node -> next;
	}
	return o<< endl;
}

class Solution {
public:
	queue<ListNode*> findKNodes(ListNode* head, int k){
		ListNode* cur = head;
		queue<ListNode*> queue;
		queue.push(head);
		int cout = k;
		while(cur){
			if (!(cout--)){
				queue.push(cur);
				cout = k;
			}
			else cur = cur -> next;
		}
		return queue;

	}
	ListNode* getEndNode(ListNode* head){
		ListNode* cur = head;
		while(cur->next){
			cur = cur->next;
		}
		return cur;
	}
	ListNode* getReturnNode(ListNode* head, int k){
		ListNode* cur = head;
		int cout = 0;
		int value = k;
		while(cur && --value){
			if (cur -> next) ++cout;
			cur = cur -> next;
		}
		return (cout ==(k-1))?cur: head;
	}

    ListNode* reverseKGroup(ListNode* head, int k) {
        if ( head == nullptr ) return nullptr;
        if (head -> next == nullptr) return head;
        if (k ==1) return head;

        queue<ListNode*> reverseHeads = findKNodes(head,k);
        ListNode* returnNode = getReturnNode(head,k);
        ListNode* endNode = getEndNode(head);
        int times = 0;
        ListNode* continueNode;

        while(!reverseHeads.empty()){
        	/*
	        	if (reverseHeads.size() == 1){
	        		continueNode = reverseHeads.front() -> next;
	        	}
	        	*/
        	ListNode* node = reverseHeads.front();
        	reverseHeads.pop();
        	ListNode* pre = node;
        	if (node -> next == nullptr) break;
        	if (endNode -> val <(node -> val + k -1)) break;
        	ListNode* mid = node -> next;
        	times = k;
     
        	while (mid  &&  --times){
        		ListNode* post = mid -> next;
        		node -> next = post;
        		mid -> next = pre;
        		pre = mid;
        		mid = post;
        	}
        	node -> next =  getReturnNode(reverseHeads.front(),k);

        }
        //returnNode -> next = continueNode;
        return returnNode;

    }
};

int main(int argc, char ** argv){
	
	//ListNode n1(8,NULL);
	//ListNode n2(7,&n1);
	ListNode n3(6,NULL);
	ListNode n4(5,&n3);
	ListNode n5(4,&n4);
	ListNode n6(3,&n5);
	ListNode n7(2,&n6);
	ListNode n8(1,&n7);

	Solution sol;
	cout << sol.reverseKGroup(&n8,2);

	/*
	while(!check.empty()){
		cout << check.front() -> val << endl;
		check.pop();
	}*/


	return 0;
}