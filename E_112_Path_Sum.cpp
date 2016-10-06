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
    vector<int> values;
    void pathSum(TreeNode* root, int sum, int dest){
        if (root == nullptr ) {
            return;
        }
        int val = root -> val + sum;
        
        if (root -> left){
            pathSum(root->left,val,dest);
        }
        if (root -> right){
            pathSum(root->right,val,dest);
        }
        if (root -> left == nullptr && root -> right == nullptr)
            values.push_back(val);
        return;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        if (root ->val == sum && root -> left == nullptr && root-> right == nullptr) return true;
        pathSum(root,0,sum);
        for (int a : values){
            cout << a << endl;
            if (a == sum) return true;
        }
        return false;
              
    }
};

int main(int argc, char ** argv){

    return 0;
}