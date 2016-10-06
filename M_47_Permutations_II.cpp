#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;


class Solution {
private:
	void permute(vector<vector<int>>& v, vector<int>& nums, int index, int size){

		if(index == (size-1)){
			v.push_back(nums);
			return;
		}
		
		for(int i = index; i < size; ++i){
			if (i != index && nums[i] == nums[index]) continue;
			swap(nums[i],nums[index]);
			permute(v,nums,index+1,size);
			swap(nums[i],nums[index]);
			
		}
		return;

	}

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(!nums.size()) return vector<vector<int>>();

        vector<vector<int>> v;

        sort(nums.begin(),nums.end());
        permute(v,nums,0,nums.size());

        //std::vector<vector<int>> v(s.begin(),s.end());
        cout << v.size();

        for_each(v.begin(),v.end(),[](vector<int> s){ for(int v : s) cout << v <<" ";
        	cout << endl;
    	});
        return v;

    }

    void  dfsHelper(vector<vector<int>>  &res, vector<int> &path, unordered_map<int, int> &numMap, int len)
    {
        if(path.size()==len) {
        	res.push_back(path);
        	return;
        }
        for(auto it = numMap.begin(); it != numMap.end(); ++it)
        {
            if(it->second)
            {	
                path.push_back(it->first); // update the current path
                --(it->second); // and map
                dfsHelper(res, path, numMap, len); // then do dfs at the next level
                path.pop_back(); // backtracking by recovering path and map
                ++(it->second);
            }
        }
    }

    vector<vector<int>> permuteUnique2(vector<int>& nums) {
        int i,len = nums.size();
        vector<vector<int>> res;
        if(len>0)
        {
            vector<int> path;

            unordered_map<int, int> numMap; //generate a map
            for(i=0; i<len; ++i) ++numMap[nums[i]];

            dfsHelper(res, path, numMap, len);
        }
        
        for_each(res.begin(),res.end(),[](vector<int> s){ for(int v : s) cout << v <<" ";
        	cout << endl;
    	});
        return res;
        
        
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	std::vector<int> v = {1,2,3};

	s.permuteUnique2(v);
	return 0;
}