#include <iostream>
#include <string>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
private:
	bool dfs(TreeNode* start, TreeNode* end){
		if(!start) return false;

		if(start -> left == end || start -> right == end) return true;

		bool l = dfs(start -> left);
		bool r = dfs(start -> right);

		return l || r;
	}	
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if (left && right) return root;
        else if(!left && right) return right;
        else if(!right && left) return left;
        else return nullptr;

    }
};