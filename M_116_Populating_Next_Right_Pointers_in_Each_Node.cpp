/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

#include <vector>

class Solution {
public:

	int height(TreeLinkNode* root){
		if (!root) return 0;

		int left = height(root->left);
		int right = height(root->right);
		//post order sequence of check

		if (left > right) return left + 1;
		else return right + 1; 

	}

	vector<vector<TreeLinkNode*>> v;

	void levelOrder(TreeLinkNode* root,int depth){
		if (root == nullptr) return nullptr;

		if (v.size() == depth){
			return v.push_back(vector<TreeLinkNode*>());
		}
		v[depth].push_back(root);
		levelOrder(root->left, depth+1);
		levelOrder(root-> right, depth+1);
	}


     void connect(TreeLinkNode *root) {
        if (!root) return;
        levelOrder(root,0);
        if(v.size() == 1){
            v[0][0] -> next = nullptr;
            return;
        }
        for_each(v.begin(),v.end(),[](vector<TreeLinkNode*> ele){
        	for(int i =0; i< ele.size()-1;ele[i] -> next = ele[i+1],++i);
        });
    }
};

int main(int argc, char ** argv){


}