#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows < 1) return ans;
        for(int i = 0; i < numRows;i++,ans.push_back(vector<int>(i)));

        //initize the first vector	
        ans[0][0] = 1;
        for(int i = 1; i < ans.size();++i){
        	for(int j = 0; j < ans[i].size();++j){
        		if (j == 0 || j == ans[i].size()-1) ans[i][j] = 1;
        		else ans[i][j] = ans[i-1][j]+ans[i-1][j-1];
        	}
        }
        return ans;
    }
};


int main(){
	Solution s;
	std::vector<vector<int>> v;

	v = s.generate(3);
	for_each(v.begin(),v.end(),[](vector<int> a){ for(int i : a) cout << i; cout << endl; });

}