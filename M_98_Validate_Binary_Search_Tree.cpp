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
    vector<int> vect;
    unordered_set<int> set;
    void postOrder(TreeNode* root){
        if (root == nullptr) return;
        postOrder(root->left);
        vect.push_back(root->val);
        set.insert(root -> val);
        postOrder(root -> right);
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (root -> left == nullptr && root -> right == nullptr) return true;
        postOrder(root);
        if (set.size() == vect.size())
            return is_sorted(vect.begin(),vect.end());
        else 
            return false;
    }
};

int main(int argc, char ** argv){

	return 0;
}