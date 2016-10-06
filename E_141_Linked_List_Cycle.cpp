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
    bool hasCycle(ListNode *head) {
        ListNode* cur = head;
        unordered_map<ListNode*, bool> u;
        if (cur == nullptr || cur -> next == nullptr ) return false;
        for(;cur;){
            if (u.find(cur) == u.end())
                u.insert({cur,true});
            else 
                return true;
            
            //if (cur -> next ) 
            cur = cur -> next;
            //else break;
        }
        return false;
    }
};

int main(int argc, char ** argv){

}