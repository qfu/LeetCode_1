#include <vector>
#include <iostream>


using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
	void inorderTraversal(vector<TreeNode*>& vec, TreeNode* node){
		if(!node) return;
		inorderTraversal(vec,node->left);
		vec.push_back(node);
		inorderTraversal(vec,node->left);
	}

	TreeNode** findParent(TreeNode* root, TreeNode* target){
		if(root == target) return &root;
		if(root->left)  return findParent(root->left,target);
		if(root ->right) return findParent(root->right,target);
	}

    void recoverTree(TreeNode* root) {
    	if(!root) return nullptr;

    	vector<TreeNode*> vec;
    	vector<TreeNode*> target;

    	inorderTraversal(vec,root);

    	int size = vec.size();
    	//This is not going to work because more than one node will be affected

 
    	//the operation of swap 

        
    }
};






int main(){

}