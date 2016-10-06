#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 
class Solution {
private:
	void levelOrder(TreeNode* root, int level, vector<set<int,greater<int>>>& container){

		if(!root) return;

		if(container.size() == level) container.push_back(set<int,greater<int>>());

		container[level].insert(root->val);
		levelOrder(root->left, level+1,container);
		levelOrder(root->right, level+1,container);

	}
	int simpleRob(int* dp,int size){
		int result[size+1];
		memset(result,0,sizeof(result));
		result[1] = dp[0];

		for(int i = 2; i < size+1; ++i){
			result[i] = max(result[i-1],result[i-2] + dp[i-1]);
		}
		return result[size];

	}


public:
    int rob2(TreeNode* root) {
        if(!root) return 0;
        vector<set<int,greater<int>>> container;

        levelOrder(root,0,container);


        //for_each(container.begin(),container.end(),[](set<int,greater<int>> s){ for(int i : s) cout << i; cout << endl; });
        int evenSum = 0;
        int oddSum = 0;
        int n = container.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < n; ++i){
        	auto start = container[i].begin();
        	auto end = container[i].end();
        	int cSize = container[i].size();

        	if(i % 2){
        		if(cSize){
        			oddSum += *start;
        		}
        		if(++start != end){
        			oddSum += *start;
        		}
        		dp[i] = oddSum;
        		oddSum = 0;
        	}else{
        		if(cSize){
        			evenSum += *start;
        		}
        		if(++start != end){
        			evenSum += *start;
        		}
        		dp[i] = evenSum;
        		evenSum = 0;
        	}
        }

        int result = simpleRob(dp,n);

        return result;

    }

   int rob(TreeNode* root) {
 		unordered_map<TreeNode*,int> map;
 		return robHelp(map,root);
	}

	int robHelp(unordered_map<TreeNode*,int>& map, TreeNode* root){
		if(!root) return 0;
		if(map.find(root)!= map.end()) return map.find(root)->second;

		int val = 0;

		if(root -> left){
			val += robHelp(map,root -> left -> left)+robHelp(map,root -> left -> right);
		}

		if(root -> right){
			val += robHelp(map,root -> right -> left) + robHelp(map,root -> right -> right);
		}
		val = max(val + root->val,robHelp(map,root->left) + robHelp(map,root->right));
		map[root]=val;

		return val;
	}

};

int main(int argc, char const *argv[])
{
	
	 
	 TreeNode* n1 = new TreeNode(3);
	 TreeNode* n2 = new TreeNode(4);
	 TreeNode* n3 = new TreeNode(5);
	 n1 -> left = n2;
	 n1 -> right = n3;
	 TreeNode* n4 = new TreeNode(1);
	 TreeNode* n5 = new TreeNode(3);
	 n2 -> left = n4;
	 n2 -> right = n5;
	 TreeNode* n6 = new TreeNode(1);
	 n3 -> right = n6;




    
/*
	 TreeNode* n1 = new TreeNode(3);
	 TreeNode* n2 = new TreeNode(2);
	 TreeNode* n3 = new TreeNode(3);
	 n1 -> left = n2;
	 n1 -> right = n3;
	 TreeNode* n4 = new TreeNode(3);
	 TreeNode* n5 = new TreeNode(1);
	 n2 -> right = n4;
	 n3 -> right = n5;
	 */

	 Solution s;
	 cout << s.rob(n1);


	/* code */
	return 0;
}