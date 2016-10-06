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
    vector<int> preorderTraversal(TreeNode* root) {
    	std::vector<int> v;
    	if(!root) return v;

    	stack<TreeNode*> s;
    	s.push(root);

    	while(!s.empty()){
    		TreeNode* n = s.top();
    		v.push_back(n->val);
    		s.pop();

    		if(n -> left) s.push(n->left);
    		if(n -> right) s.push(n->right);
    	}
    	return v;

    }
};

int main(){

}