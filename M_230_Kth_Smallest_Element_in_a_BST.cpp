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

	std::vector<int> v;
	void inorder(TreeNode* root){
		if (!root) return;
		inorder(root->left);
		v.push_back(root -> val);
		inorder(root->right);
	}

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        inorder(root);
        return v[k-1];
    }
};





int main(){

}