#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */


class Solution {
private:
	void levelOrder(TreeLinkNode* node, int level,vector<vector<TreeLinkNode*>>& result){
		if(!node) return;

		if(result.size() == level) result.push_back(vector<TreeLinkNode*>());
		result[level].push_back(node);
		levelOrder(node->left,level+1,result);
		levelOrder(node->right,level+1,result);
	}
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        vector<vector<TreeLinkNode*>>& nodes;
        levelOrder(root,0,nodes);
        for(int i = 0; i < nodes.size();++i){
        	for(int j = 0; j < nodes[i].size()-1;nodes[j]->next = nodes[j+1],++j);
        }
    }
};

int main(int argc, char ** argv){

}