#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;


class Solution {
public:

	
	unordered_set<int> s;


	void backtrack(int i, vector<int>& nums,vector<int>& v, vector<vector<int>>& ans, bool * table, int size){
		if(size == 0){
			ans.push_back(v);
			return;
		}

		if(v.size()!= 1){
		 	v.push_back(i);
		 	s.insert(i);
		}
		for(int i = 0; i < nums.size(); ++i){
			if(!table[nums[i]] && s.find(i) == s.end()){
				backtrack(nums[i],nums,v,ans,table,size-1);
				v.pop_back();
				s.erase(s.end());
			}
		}
		return;

	}



    vector<vector<int>> permute2(vector<int>& nums) {
        std::vector<vector<int>> ans;
        bool * table = new bool[nums.size()];
        memset(table,0,nums.size());
        
        vector<int> v;

        for(int i : nums){
        	v.push_back(i);
        	s.insert(i);
        	table[i] = true;
        	backtrack(i,nums,v,ans,table,nums.size()-1);
        	v.pop_back();
        	s.erase(s.end());
        }
        return ans;
    }



	vector<vector<int>> ans;

	void helper(vector<int>& nums,int i,int j){

		if(i == j){
			for_each(nums.begin(),nums.end(),[](int l){ cout << l;});
			ans.push_back(nums);
		}
		//already boundary check
		for(int l = i; l <= j; ++l){
			swap(nums[l],nums[i]);
			helper(nums,i+1,j);
			swap(nums[l],nums[i]);
		}

	}


    vector<vector<int>> permute(vector<int>& nums) {
    	 helper(nums,0,nums.size()-1);
    	 return ans;
	}



};


int main(){
	std::vector<int> v = {1,2,3};

	Solution s;

	s.permute(v);
	

	vector<vector<int>> a =  s.permute(v);
	for(auto & x :a){
		for_each(x.begin(),x.end(),[](int l){ cout << l;});
		cout << endl;
	}
}