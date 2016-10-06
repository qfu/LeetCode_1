#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
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
	void insertTree(TreeNode** root, int value, unordered_map<int,int>& map){
		if(*root == nullptr){
			*root = new TreeNode(value);
			return;
		}
		if( map[(*root) -> val] > map[value]){
			insertTree(&((*root)->left),value,map);
		}
		else{
			insertTree(&((*root)->right),value,map);
		}

	}


	void insertTree2(TreeNode** root, int value, unordered_map<int,int>& map){
		while(1){
			if(*root == nullptr){
				*root = new TreeNode(value);
				break;
			}
			if( map[(*root) -> val] > map[value]){
				//insertTree(&((*root)->left),value,map);
				root = &((*root)->left);
			}
			else{
				//insertTree(&((*root)->right),value,map);
				root = &((*root)->right);

			}
		}
		return;
	}

	void insertTree3(TreeNode** root, int value, vector<int> & inorder){
		while(1){
			if(*root == nullptr){
				*root = new TreeNode(value);
				break;
			}
			if( find (inorder.begin(), inorder.end(),(*root) -> val) > find (inorder.begin(), inorder.end(), value)){
				//insertTree(&((*root)->left),value,map);
				root = &((*root)->left);
			}
			else{
				//insertTree(&((*root)->right),value,map);
				root = &((*root)->right);

			}
		}
		return;
	}



	void inorderT(TreeNode* node){
		if(node == nullptr){
			return;
		}
		inorderT(node->left);
		cout << node -> val << " ";
		inorderT(node->right);
	}

	void preorderT(TreeNode* node){
		if(node == nullptr){
			return;
		}
		cout << node -> val << " ";
		inorderT(node->left);
		inorderT(node->right);
	}



    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	if(!preorder.size() || !inorder.size()) return nullptr;
    	TreeNode* root = NULL;
    	unordered_map<int,int> map;
    	//preorder.erase(preorder.begin());
    	for(int i = 0; i < inorder.size(); ++i){
    		map[inorder[i]] = i;
    	}


    	for(int value: preorder){
    		//cout << value;
    		//insertTree2(&root,value,map);
    		insertTree3(&root,value,inorder);
    	}
  

    	inorderT(root);
    	cout << endl;
    	preorderT(root);
        
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    	return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}

	TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
    	if(ps > pe){
        	return nullptr;
    	}
    	TreeNode* node = new TreeNode(preorder[ps]);
    	int pos;
    	for(int i = is; i <= ie; i++){
        	if(inorder[i] == node->val){
            	pos = i;
            	break;
        	}
    	}
    	node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
    	node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
    	return node;
	}
};

int main(int argc, char ** argv){
	std::vector<int> v1 = {4,7,2,1,10,3,5};
	std::vector<int> v2 = {2,7,1,4,3,10,5};

	Solution s;
	s.buildTree(v1,v2);


	return 0;
}

