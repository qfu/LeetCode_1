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
    vector<vector<int>> build;
    void levelOrder(TreeNode* root, int level){
        if (root == nullptr) return;
        if (build.size() == level)
            build.push_back(vector<int>());
        if (level % 2 == 0)
            build[level].push_back(root ->val);
        else 
            build[level].insert(build[level].begin(),root ->val);

        levelOrder(root -> left, level +1);
        levelOrder(root -> right, level +1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        levelOrder(root,0);
        return build;
    }
};

int main(int argc, char ** argv){

	return 0;
}