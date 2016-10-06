#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:

	void backtrack(vector<vector<int>>& ans,vector<int>& nums, vector<int>& temp,int begin,int size){
		if(size == temp.size()){
			ans.push_back(temp);
			return;
		}

		for(int i = begin; i < nums.size();++i){
			temp.push_back(nums[i]);
			backtrack(ans,nums,temp,i+1,size);
			temp.pop_back();
		}
		return;
	}




    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;

        for(int i = 0; i <= size; ++i){
        	backtrack(ans,nums,temp,0,i);
        }

        auto predicate = [](vector<int> a, vector<int> b){
        	if(a.size()==b.size()){
        		for(int i = 0; i < a.size();++i) if(a[i] != b[i]) return true;
        		return false;
        	}
        	return false;
        };
        for_each(ans.begin(),ans.end(),[](vector<int>& a){ sort(a.begin(),a.end()); });
        sort(ans.begin(),ans.end());
        auto it = unique(ans.begin(), ans.end());
        ans.resize( distance(ans.begin(),it));
        return ans;
    }
};


int main(int argc, char** argv){

	Solution s;
	
	vector<int> v = {4,4,4,1,4};
	vector<vector<int>> a = s.subsetsWithDup(v);
	for(auto & x :a){
		for_each(x.begin(),x.end(),[](int l){ cout << l;});
		cout << endl;
	}

	return 0;


}