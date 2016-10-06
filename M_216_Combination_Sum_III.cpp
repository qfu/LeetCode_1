#include <vector>
#include <iostream>


using namespace std;

class Solution {
private:
	void backtrack(vector<vector<int>>& result, vector<int>& vec, int index, int k, int n){
		if(k == 0){
			if(n == 0) result.push_back(vec);
			return;
		}

		for(int i = index; i <= 9; ++i){
			vec.push_back(i);
			backtrack(result, vec,i+1,k-1,n-i);
			vec.pop_back();
		}
	}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> vec;
        backtrack(result,vec,1,k,n);

        for(auto & x : result){
        	for(auto & y : x){
        		cout << y << " ";
        	}
        	cout << endl;
        }
        return result;
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	s.combinationSum3(3,9);
	return 0;
}