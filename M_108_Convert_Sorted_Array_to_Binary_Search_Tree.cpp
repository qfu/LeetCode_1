#include <vector>
#include <string>
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
	TreeNode* insertTree(vector<int>& nums, int left, int right){
		if(left > right) return nullptr;
		if(left == right){
			return new TreeNode(nums[left]);
		}
		int mid = (left+right)/2;
		TreeNode* newNode = new TreeNode(nums[mid]);
		newNode -> left = insertTree(nums,left,mid-1);
		newNode -> right = insertTree(nums,mid+1,right);
		return newNode;
	}

	void inorderTraversal(TreeNode* node){
		if (!node) return;
		inorderTraversal(node ->left);
		cout << node -> val << " " << endl;
		inorderTraversal(node -> right);
	}



	TreeNode* sortedArrayToBST(vector<int>& nums) {
		//mid elements is the root of the tree
		if(!nums.size()) return nullptr;

		//inorderTraversal(insertTree(nums,0,nums.size()-1));
		return insertTree(nums,0,nums.size()-1);

    }


};


int main(){
	Solution s;
	std::vector<int> v = {1,2,3,4,5,6};

	s.sortedArrayToBST(v);
}