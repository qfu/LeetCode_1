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
 using namespace std;

 class TreeNode{
 public:
 	int val;
 	TreeNode* left;
 	TreeNode* right;
 	TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l),right(r){}
 };
class Solution {
public:
	queue<TreeNode*> q;
	void traverse(TreeNode* root){
	   if (root == nullptr) return ;
       q.push(root);
       if (root -> left) traverse(root -> left);
       if (root -> right) traverse(root -> right);
	}

    void flatten(TreeNode* root) {
    	if (root == nullptr) return ;
    	traverse(root);
    	TreeNode* n = q.front();
    	q.pop();
    	while(!q.empty()){
    		TreeNode* temp = q.front();
    		q.pop();
    		//cout << n ->val;
    		//cout << temp -> val;
    		n -> left = nullptr;
    		n -> right = temp;
    		n = temp;
    	}
    }
};

int main(int argc, char ** argv){
	TreeNode t3(3,nullptr,nullptr);
	TreeNode t4(4,nullptr,nullptr);
	TreeNode t6(6,nullptr,nullptr);
	TreeNode t5(5,nullptr,&t6);
	TreeNode t2(2,&t3,&t4);
	TreeNode t1(1,&t2,&t5);
	Solution solver;

	solver.flatten(&t1);
	TreeNode* check = &t1;

	while(check){
		cout << check -> val;
		check = check -> right;
	}

	return 0;
}