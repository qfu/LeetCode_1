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
#include <set>
#include <functional>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:

	set<int,greater<int>> s;

	void dfs(TreeNode* node,int& sum,int level){
		//base case
		if(node == nullptr) return;
		sum += node -> val;
		s.insert(sum);
		if(level < 1){
			if(node ->left)dfs(node -> left,sum,level+1);
			if(node ->right)dfs(node -> right,sum,level+1);
		}
		else{
			if(node ->left && !(node->right)) dfs(node -> left,sum,level+1);
			else if ( node ->right && !(node->left)) dfs(node -> right,sum,level+1);
			else if ( node -> left && node -> right && node-> left ->val < node -> right -> val && level > 0)dfs(node -> right,sum,level+1) ;
			else if ( node -> left && node -> right && node-> left ->val > node -> right -> val && level > 0)dfs(node -> left,sum,level+1);
		}
	}


    int maxPathSum(TreeNode* root) {
 		//if(!root) return 0;
    	if(!root) return 0;

    	helper(root);
    	for_each(s.begin(),s.end(),[](int s){ cout << s << endl;});
    	return *s.begin();
    }

    void helper(TreeNode* node){
    	if(node == nullptr) return;
    	int sum = 0;
    	dfs(node,sum,0);
    	s.insert(sum);
    	helper(node->left);
    	helper(node->right);
    }
};



int main(int argc, char ** argv){
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);

	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	TreeNode node7(7);

	TreeNode node8(8);
	TreeNode node9(9);

	TreeNode node10(10);
	TreeNode node11(11);
	node1.left = &node2;
	node1.right = &node3;

	node2.left = &node4;
	node2.right = &node5;

	node3.left = &node6;
	node3.right = &node7;

	node4.left = &node8;
	node4.right = &node10;
	node5.left = &node9;
	node5.right = &node11;


	Solution s;
	int sum = 0;
	//cout << 
	cout << s.maxPathSum(&node1);
	cout << sum;
}	

