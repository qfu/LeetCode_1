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
#include <queue>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;


class Solution {
public:

	stack<TreeNode*> s;

	void pushStack(TreeNode* root){	
		while(root != nullptr){
        	s.push(root);
        	root = root -> left;
        }
	}

    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> v;
        if (!root) return v;

        pushStack(root);

        while(!s.empty()){
        	TreeNode* node = s.top();
        	s.pop();	

        	v.push_back(node -> val);
        	if (node -> right) pushStack(node->right);
        }
        return v;

    }
};

int main(int argc, char ** argv){

}