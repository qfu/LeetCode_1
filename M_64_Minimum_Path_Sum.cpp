#include <iostream>
#include <vector>
#include <cmath>
using namespace std;




class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
     	int n = grid.size();
     	int m = grid[0].size();
     	vector<vector<int>> result(n,vector<int>(m,0));
     	result[0][0] = grid[0][0];

     	for(int i = 0; i < n; ++i ){
     		for(int j = 0; j < m; ++j){
     			//in the solution check how to minimize the condition
     			if(i - 1 < 0 && j - 1 >= 0) result[i][j] = result[i][j-1] + grid[i][j];  
     			else if(j - 1 < 0 && i -1 >= 0) result[i][j] = result[i-1][j] + grid[i][j];
     			else if (j - 1 >= 0 && i -1 >= 0) result[i][j] = min(result[i-1][j]+ grid[i][j],result[i][j-1] + grid[i][j]);
     		}
     	}

     	return result[n-1][m-1];

    }
};


int main(int argc, char** argv){
	Solution s;

	std::vector<int> v1 = {3};
	std::vector<vector<int>> v  = {v1};
	cout << s.minPathSum(v);

}