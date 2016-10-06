#include <iostream>
#include <vector>


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
	vector<vector<int>> v;

	void traverse(TreeNode* root,int depth){
		if (!root) return;

		if (v.size() == depth)
			v.push_back(vector<int>());
		v[depth].push_back(root -> val);
		traverse(root -> left,depth+1);
		traverse(root -> right,depth+1);
	}

    vector<int> rightSideView(TreeNode* root) {
        if (!root) return v;
        traverse(root,0);
        
        vector<int> vec;
        for (auto & row : v){
        	vec.push_back(row.back());
        }

        return vec;
    }
};






int main(){

}