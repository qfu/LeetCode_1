/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <algorithm> 
class Solution {
public:

	vector<vector<int>> v;

	int height(TreeNode* root){
		if (!root) return 0;
		return max(height(root->left),height(root->right))+1;
	}

	void levelTraverse(TreeNode* root, int level){
		if(!root) return;

		//level is like the size
		
		if (v.size() < level) for(int i =0;i < level;v.push_back(vector<int>()),++i);
		v[level-1].push_back(root->val);
		levelTraverse(root->left,level-1);
		levelTraverse(root->right,level-1);

	}

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return v;
        levelTraverse(root,height(root));
        return v;

    }
};





int main(){

	return 0;
}