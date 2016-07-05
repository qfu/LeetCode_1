/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 #include <iostream>
 #include <stack>
 class TreeNode {
 public:
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
  };

#define MAX(a,b) (a>=b?a:b)
class Solution {
public:
    int maxDepth(TreeNode* root) {
    	//This case will work if I have a parent pointer
    	/*
    	TreeNode* cur = root;
    	stack<TreeNode*> fringe;
		fringe.push(cur -> right);
    	fringe.push(cur-> left);
    	int cout = 0;
    	while (fringe.size()){
    		TreeNode* top = fringe.top();
    		top.val += 1;
    		fringe.pop();
    		if (top -> left == NULL && top -> right == NULL){

    		}
    		fringe.push(top -> right);
    		fringe.push(top-> left);
    	}
	*/
    	//edge case 
    	if (root == NULL) return 0;
    	if (root -> left == NULL && root -> right == NULL) return 1;

    	/*
		 maxDepth()
			1. If tree is empty then return 0
			2. Else
		     	(a) Get the max depth of left subtree recursively  i.e., call maxDepth( tree->left-subtree)
		     	(a) Get the max depth of right subtree recursively  i.e., call maxDepth( tree->right-subtree)
		     	(c) Get the max of max depths of left and right subtrees and add 1 to it for the current node.
		         	max_depth = max(max dept of left subtree, max depth of right subtree) + 1
		     	(d) Return max_depth

    	*/
    	TreeNode* cur = root;

    	int max_depth = 0;


    	//This is the level where it gets return to 
    	int max_left = maxDepth(cur -> left);
    	int max_right = maxDepth(cur -> right);


    	max_depth = MAX(max_left,max_right) + 1;
    	return max_depth;
    	//when all the function on the stack are return,
    	//the call return back to the callee

        
    }
};

int main(int argc, char ** argv)){


}