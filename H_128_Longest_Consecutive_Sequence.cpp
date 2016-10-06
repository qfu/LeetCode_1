#include <vector>
#include <iostream>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
private:
	//Building a binary search tree
	//calculate how many nodes in the tree later 
	void buildTree(vector<int>& nums, int num, int & count){

		//TreeNode* node = new TreeNode(num);
		//cout << node ->val;
		cout << num;
		auto x = find(nums.begin(),nums.end(),num-1);
		auto y = find(nums.begin(),nums.end(),num+1);
		if(x != nums.end()){
			//node->left = buildTree(nums,*x);
			count += 1;
			nums.erase(x);
			buildTree(nums,*x,count);
		}
		
		if(y != nums.end()){
			//node -> right = buildTree(nums,*y);
			count += 1;
			nums.erase(y);
			buildTree(nums,*y,count);
		}
		//auto z = find(nums.begin(),nums.end(),num);
		//nums.erase(z);

		return ;
	}
	/*
	int numberNodes(TreeNode* node){	
		if(!node) return 0;
		return numberNodes(node->left) + numberNodes(node->right) + 1;
	}*/

public:
    int longestConsecutive(vector<int>& nums) {
    	if(!nums.size()) return 0;

    	set<int, greater<int>> s;

    	int search;
    	vector<int>::iterator it;
     	for(;it != nums.end();){
     		it = nums.begin();
     		int value = *it; 
     		nums.erase(it);
   			search = 1;

     		buildTree(nums,value,search);
     		s.insert(search);
     	}
     	return *s.begin();
    }
};


int main(){
	std::vector<int> v = {100, 4, 200, 1, 3, 2};
	Solution s;
	s.longestConsecutive(v);
	return 0;
}	