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
    set<int> s;
    void depthValue(TreeNode* root, int depth){
        if (root == nullptr) return;
        
        depthValue(root -> left,depth+1);
        depthValue(root -> right,depth+1);
        if (root -> left == nullptr && root -> right == nullptr) s.insert(depth);
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root -> left == nullptr && root -> right == nullptr) return 1;
        depthValue(root,1);
        return *s.begin();
    }
};