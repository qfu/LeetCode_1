#include <iostream>
#include <vector>
#include <numeric>

#include <algorithm>
using namespace std;

class Solution {
public:


	void combine(vector<vector<int>>& ans,vector<int>& candidates,vector<int>& v,int target,int begin){
		if (!target){
			ans.push_back(v);
			return;
		}
		//target >= candidates[i] is awesome 
		for(int i = begin; i < candidates.size()&& target >= candidates[i];++i){
			v.push_back(candidates[i]);
    		combine(ans,candidates, v,target-candidates[i],i);
    		v.pop_back();
		}
		return;
	}



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	
    	vector<vector<int>> ans;
    	vector<int> vec;	
    	int size = candidates.size();
    	std::sort(candidates.begin(), candidates.end());

    	combine(ans,candidates, vec,target,0);
 	
       	return ans;

    }
};


class Solution2 {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
		if  (!target) {
			res.push_back(combination);
			return;
		}
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};

int main(int argc, char** argv){
	std::vector<int> v = {8,7,4,3};
	int target = 11;
	Solution s;

	vector<vector<int>> a = s.combinationSum(v,target);
	for(auto & x :a){
		for_each(x.begin(),x.end(),[](int l){ cout << l;});
		cout << endl;
	}

	return 0;
}