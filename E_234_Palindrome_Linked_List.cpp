/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::stack<int> mystack;
        ListNode* cur = head;
        ListNode* cur2 = head;
        while(cur){
            mystack.push(cur -> val);
            
            if (cur -> next ) cur = cur -> next;
            else break;
        }
        
        while(cur2){
            if (mystack.top() == (cur2 -> val)){
                mystack.pop();
            }
            if (cur2 -> next ) cur2 = cur2 -> next;
            else break;
        }
        return (mystack.size() == 0)? true: false;
    }
};