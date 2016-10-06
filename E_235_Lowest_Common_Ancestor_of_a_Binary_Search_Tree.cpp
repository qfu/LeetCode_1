/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class TreeNode {
public:
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x,TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
  };
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {


      /* false understainding version*/ 

      /*
    	int valRoot = root -> val;
    	int valP = p -> val;
    	int valQ = q -> val;
      if (valP > valRoot && valQ > valRoot) return root;
    	if (( valP <= valRoot && valQ >= valRoot) ||(valQ <= valRoot &&  valP>= valRoot)) return root;
      if (valP < valRoot && valQ < valRoot) return lowestCommonAncestor(root -> left,p,q);
      */



      //Correct Version 
      
      int valRoot = root -> val;
      int valP = p -> val;
      int valQ = q -> val;
        //if (valP > valRoot && valQ > valRoot) return root;
      if (( valP <= valRoot && valQ >= valRoot) ||(valQ <= valRoot &&  valP>= valRoot)) return root;
      else if (valP < valRoot && valQ < valRoot && root -> left) return lowestCommonAncestor(root -> left,p,q);
      else if (valP > valRoot && valQ > valRoot && root -> right) return lowestCommonAncestor(root -> right,p,q);
      else return nullptr;
    }
};



int main(int argc , char ** argv){


	return 0;
}