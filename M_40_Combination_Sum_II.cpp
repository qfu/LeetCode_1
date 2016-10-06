#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
private:
	void backtrack(set<vector<int>>& result, vector<int>& ss, int target, int start, int size,vector<int>& candidates){
		if(target == 0){
			//do need to sort each times
			result.insert(ss);		
			return;
		}
		else if(target > 0){//if the target element is far greater than the targer prune instead of reaching to the end
			for(int i = start; i < size; ++i){
				//cout << candidates[i];
				ss.push_back(candidates[i]);
				backtrack(result,ss,target-candidates[i],i+1,size,candidates);
				ss.pop_back();
		
			}
		}
	}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	int size = candidates.size();
    	if(!size) return vector<vector<int>>();

    	sort(candidates.begin(),candidates.end());

    	set<vector<int>> result;

    	vector<int> ss;

    	backtrack(result,ss,target,0,size,candidates);
 	
  		

    	//return result;
    	return vector<vector<int>>(result.begin(),result.end());

        
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	std::vector<int> v = {2,5,2,1,2};

	vector<vector<int>> result = s.combinationSum2(v,5);



    	
    	for(auto& it : result){
    		for(auto & x : it){
    			cout << x  << " ";
    		}
    		cout << endl;
    	}
	return 0;
}