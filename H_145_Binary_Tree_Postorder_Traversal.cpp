#include <vector>
#include <iostream>
#include <stack>

using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



class Solution {

private:
	void dfs(vector<int>& vec,stack<TreeNode*>& s){
		while(!s.empty()){
			TreeNode* visited = s.top();
			s.pop();

			vec.push_back(visited->val);

			if(visited -> left) s.push(visited -> left);
			if(visited -> right) s.push(visited -> right);
		}
	}

public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();

        vector<int> v;
        stack<TreeNode*> s;
        s.push(root);
        dfs(v,s);
        reverse(v.begin(),v.end());
        return v;
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}