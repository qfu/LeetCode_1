class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;
        ListNode* prev = new ListNode(-1);
        prev -> next = head;
        ListNode* returnNode = prev;
        ListNode* cur = head;
        while(cur){
            if (cur ->val == val){
                prev -> next = cur -> next;
                cur = prev -> next;
                continue;
            }
            prev = prev -> next;
            cur = cur -> next;
        }
        return returnNode-> next;
        
    }
};