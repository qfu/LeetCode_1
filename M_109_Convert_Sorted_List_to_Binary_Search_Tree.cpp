/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	void buildTree(TreeNode* root, ListNode* head){
		while(head){
			insertTree(root,head);
			head = head -> next;
		}
	}


	void insertTree(TreeNode* root, ListNode* head){
        
        if (head == nullptr) return;
        
		if (root -> val == head -> val){
			return;
		}
		else if (root -> val < head -> val){
			if (!root-> right){ 
				root -> right = new TreeNode(head -> val);
			}
			else buildTree(root->right,head);
		}else{
			if (!root-> left){
				root -> left = new TreeNode(head -> val);
			}
			else buildTree(root->left,head);
		}
	}


    TreeNode* sortedListToBST(ListNode* head) {
    	if (head == null) return nullptr;
        ListNode* cur = head;

       	ListNode* fast = cur;
       	while(fast -> next){
       		fast = fast -> next -> next;
       		cur = cur -> next;
       	}
       	TreeNode* root = new TreeNode(cur-> val);

       	buildTree(root,head);
       	return root
    }
};

int main(){

	return 0;
}