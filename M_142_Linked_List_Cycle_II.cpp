/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <unordered_map>

using namespace std;
class ListNode {
	int val;
	ListNode* next;
	ListNode(int x, ListNode* n):val(x),next(n){}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	if (head == nullptr) return NULL;
        ListNode* cur = head;
        unordered_map<ListNode*,bool> map;

        while(cur){	
        	if (map.find(cur) == map.end())
        		map.insert({cur,true});
        	else return map.find(cur) -> first;
        	cur = cur -> next;
        }
        return nullptr;
    }	
};


int main(int argc, char ** argv){


	return 0;
}