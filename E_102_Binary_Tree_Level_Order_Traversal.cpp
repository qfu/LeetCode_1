/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;




class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
   	
   	vector<vector<int>> returnV;
   	queue<TreeNode*> queue;
    //Check edge 
    if (root == nullptr ) return NULL;

    returnV.push_back({root -> val});
    queue.push(root);

    //Added the concept of level 
    //Use queue.size() to keep track
    int cout = 0;
    vector<int> internV;
    while(!queue.empty()){
    	TreeNode* cur = queue.front();
    	queue.pop();
    	if (cur -> left){
    		queue.push(cur -> left);
    		internV.push_back(cur -> left ->val);
    		cout +=1;
    	}
    	if (cur -> right){
    		queue.push(cur -> right);
    		internV.push_back(cur -> right ->val);
    		cout +=1
    	}
    	if (cout == queue.size()){
    		returnV.push_back(internV);
    		internV.clear();
    		cout = 0;
    	}

    }
    for (int i = 0; i < returnV.size();++i){
        if(returnV[i].size() == 0) returnV.erase(returnV.begin()+i);
    }
        
    }
};



int main(int argc, char ** argv){

	return 0;
}