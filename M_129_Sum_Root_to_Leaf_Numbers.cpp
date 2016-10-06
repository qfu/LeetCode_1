#include <iostream>
#include <vector>
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
private:

	void dfs(TreeNode* root,vector<vector<int>>& container,vector<int>& vec){
		if(!root) return;	

		vec.push_back(root->val);
		dfs(root->left,container,vec);
		dfs(root->right,container,vec);

		if(!(root -> left) && !(root->right)) container.push_back(vec);
		vec.pop_back();

	}


public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        vector<vector<int>> container;
        vector<int> vec;

        dfs(root,container,vec);

        int bigSum = 0;

        for(auto ele : container){
        	int i = 1;
        	int sum = 0;
        	for(int j = ele.size() -1 ; j >= 0; --j){
        		sum += ele[j]* i;
        		i *= 10;
        	}
        	bigSum += sum;
        }
        return bigSum;

    }
};


int main(){
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);

	t1 -> left = t2;
	t1 -> right = t3;

	Solution s;
	cout << s.sumNumbers(t1);

}