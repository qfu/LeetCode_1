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
  	bool flag = true;

	void traverse(TreeNode* p, TreeNode* q){
		if(!p || !q){
			if (flag) flag = (p||q)?false:true;
			return;
		}

		if (p ->val != q -> val) flag = false;
		traverse(p->left,q->left);
		traverse(p->right,q->right);

	}



    bool isSameTree(TreeNode* p, TreeNode* q) {
        traverse(p,q);
        return flag;
    }
};


int main(){

}