#include <vector>
#include <iostream>
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
private:
	TreeNode* helper(vector<int>& inorder,  vector<int>& postorder,int start, int end,int index){
		if(end - start <= 1){
			TreeNode* n = new TreeNode(postorder.front());
			postorder.erase(postorder.begin());
			return n;
		}

		int i = start;
		for (; i < end; ++i){
			/* code */
			if(inorder[i] == postorder.front()) break;
		}

		TreeNode* node = new TreeNode(postorder.front());
		postorder.erase(postorder.begin());

		node -> right = helper(inorder,postorder,i+1,end,index+1);

			
		node -> left = helper(inorder,postorder,start,i,index+1); 

		return node;
	}


public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	if(!inorder.size() || !postorder.size()) return nullptr;


		reverse(postorder.begin(),postorder.end());

		Test(helper(inorder,postorder, 0,inorder.size()-1,0));
		
		//return helper(inorder,postorder, 0,inorder.size()-1,0);        
    }

    void Test(TreeNode* node){
    	if(!node) return;
    	Test(node -> left);
    	cout << node ->val;
    	Test(node -> right);
    }
};






int main(int argc, char const *argv[])
{

	std::vector<int> post = {3,1,2} ;
	std::vector<int> in = {3,2,1};
	/* code */
	Solution s;
	s.buildTree(in,post);





	return 0;
}