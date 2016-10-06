#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 
class Solution {
public:
	void dfs(TreeNode* node){
		if(node == nullptr) return;
		cout << node -> val << " ";
		dfs(node->left);
		dfs(node->right);
	}


	TreeNode* clone(TreeNode* root){
		if(root == nullptr) return nullptr;

		TreeNode* cloneNode = new TreeNode(root->val);
		cloneNode ->left = clone(root->left);
		cloneNode ->right = clone(root->right);

		return cloneNode;
	}

    vector<TreeNode*> generateTrees(int n) {
        
    	vector<TreeNode*> result;
    	result.push_back(new TreeNode(1));

    	if( n==1 ) return result;
    	for(int i = 2; i <= n; ++i){
    		vector<TreeNode*> nextLevel;
    		//for each old roots
    		TreeNode* newNode = new TreeNode(i);
    		for(int j = 0; j < result.size();++j){
    	
    			//might have to search down the tree
    			TreeNode* oldNode = result[j];
    			TreeNode* oldNodeReference = oldNode;
    			newNode -> left = oldNode;
    			nextLevel.push_back(clone(newNode));
    			newNode -> left = nullptr;

    			//This is the replacement operation
    			while(oldNodeReference->right){
    				TreeNode* temp = oldNodeReference->right;
    				oldNodeReference -> right = newNode;
    				newNode -> left = temp;
    				nextLevel.push_back(clone(oldNode));
    				//complete restore to the old tree
    				oldNodeReference -> right = temp;
					newNode -> left = nullptr;
    				oldNodeReference = oldNodeReference -> right;
    			}
    			//newNode->left = nullptr;
    			oldNodeReference -> right = newNode;
    			nextLevel.push_back(clone(oldNode));
    			oldNodeReference -> right = nullptr;
  				

    		}
    		delete newNode;
    		result = nextLevel;
    	}
    	return result;
    }
};


int main(int argc, char **argv){

	Solution s;
	std::vector<TreeNode*> vec = s.generateTrees(4);

	for(auto & node: vec ){
		s.dfs(node);
		cout << endl;
	}

	return 0;
}


