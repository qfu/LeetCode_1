#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
	vector<vector<int>> ans;

	void backtrack(vector<int>& nums,vector<int>& v, int begin, int size){
		if(v.size() == size){
			ans.push_back(v);
			return;
		}
			
		for(int i = begin; i < nums.size(); ++i){
			v.push_back(nums[i]);
			backtrack(nums,v,i+1,size);
			v.pop_back();
		}
		return;

	}


	void combine(vector<int>& nums, int size ){
		

		vector<int> v;
		backtrack(nums,v,0,size);
		return;

	}




    vector<vector<int>> subsets(vector<int>& nums) {
    	
    	int size = nums.size();

		vector<int> v;

    	for(int i =0; i <= size; ++i){
			backtrack(nums,v,0,i);
    	}
    	return ans;
    }
};

int main(int argc, char ** argv){
	Solution s;
	
	vector<int> v = {1,2,3,4};
	vector<vector<int>> a = s.subsets(v);
	for(auto & x :a){
		for_each(x.begin(),x.end(),[](int l){ cout << l;});
		cout << endl;
	}

	return 0;
}