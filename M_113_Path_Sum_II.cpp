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
	void helper(vector<vector<int>>& v, vector<int>& vec, int sum, TreeNode* root){
		if(!root){
		 	return;
		}

		cout << sum << endl;
		vec.push_back(root->val);
		sum -= root ->val;

		if(sum == 0){
		 	v.push_back(vec);
		 	vec.pop_back();
		 	return;
		}

		helper(v,vec,sum,root->left);
		helper(v,vec,sum,root->right);
		vec.pop_back();
		//sum += root -> val;
		return;

	}


public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<vector<int>> v;
		if(!root) return v;

		std::vector<int> vec;



		helper(v,vec,sum,root);
		for_each(v.begin(),v.end(),[](vector<int> v){ for(int i : v) cout << i;});


		return v;

    }
};


int main(){

	/*
      		  5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
        */
    TreeNode* n1 = new TreeNode(-2);
    //TreeNode* n2 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(-3);
    //n1->left = n2;
	n1->right = n3;

/*
    TreeNode* n4 = new TreeNode(11);
    TreeNode* n5 = new TreeNode(13);
    TreeNode* n6 = new TreeNode(4);

	n3->left = n5;
	n3->right = n6;

	n2 -> left = n4;


    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(2);
    n4->left = n7;
	n4->right = n8;
    TreeNode* n9 = new TreeNode(5);
    TreeNode* n10 = new TreeNode(1);

	n6->left = n9;
	n6->right = n10;
*/
	Solution s;
	s.pathSum(n1,-5);


}