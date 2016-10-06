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
    ListNode *next;
    ListNode(int x,ListNode* n) : val(x), next(n) {}
};
class Solution {
public:
	static int listLength(ListNode* head){
		ListNode* cur = head;
		int cout  = 0;
		while(cur){
			cout +=1;
			cur = cur -> next;
		}
		return cout;
	}
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return NULL;
        if (head -> next == nullptr && n == 1 ) return NULL;

        ListNode* cur = head;
        ListNode* pre = new ListNode(-1,cur);
        ListNode* dummy = pre;
        ListNode* post = head -> next;
        int iter = listLength(head) - n ;
        while(cur && iter--){
        	cur = cur ->next;
        	pre = pre -> next;
        	post = post -> next;
        }
        pre -> next =post;
        return dummy -> next;
    }
};

int main(int argc, char ** argv){
	ListNode n2(7,NULL);
	ListNode n3(6,&n2);
	ListNode n4(5,&n3);
	ListNode n5(4,&n4);
	ListNode n6(3,&n5);
	ListNode n7(2,&n6);
	ListNode n8(1,&n7);

	ListNode* check = Solution::removeNthFromEnd(&n8,1);
	while (check){
		cout << check -> val;
		check = check -> next;
	}
	return 0;
}