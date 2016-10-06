/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <iostream>
 #include <set>
 using namespace std;
 class TreeNode {
 public:
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x,TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class BSTIterator {
public:
    set<int> nodeSet;
    set<int>::iterator it;
    set<int>::iterator end;
    
    void orderTreeNodes(TreeNode* root){
        if (root == nullptr) return;
        orderTreeNodes(root->left);
        nodeSet.insert(root -> val);
        orderTreeNodes(root->right);
    }
    
    BSTIterator(TreeNode *root) {
        orderTreeNodes(root);
        it = nodeSet.begin();
        end = nodeSet.end();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (it != end) return true;
        else return false;
        
    }

    /** @return the next smallest number */
    int next() {
        return *(it++);
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

 int main(){
    TreeNode* t3 = new TreeNode(7,NULL,NULL);
    TreeNode* t2 = new TreeNode(2,NULL,NULL);
    TreeNode* t1 =new TreeNode(5,t2,t3);
    BSTIterator i = BSTIterator(t1);
    while (i.hasNext()) cout << i.next();

 }


