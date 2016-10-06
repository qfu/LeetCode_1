#include <vector>
#include <iostream>
#include <climits>
#include <functional>
#include <set>
using namespace std;

class Solution {
private:

	//whole function should return the max distance
	int dfs(vector<vector<int>>& matrix, int i, int j, int n, int m, int first, int maxLen, vector<vector<int>>& cache){
		if(i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] <= first){
			return 0;
		}

    //I have explored this state and already 
    //update all possible paths so if I reach to this state again
    //I will redirectly return to prevent further deepening
		if(cache[i][j]) return cache[i][j];

		int prev = matrix[i][j];
		matrix[i][j] = INT_MIN;
		//maxLen += 1;

		int up = dfs(matrix,i-1,j,n,m,prev,maxLen,cache);
		int down = dfs(matrix,i+1,j,n,m,prev,maxLen,cache); 
	 	int left = dfs(matrix,i,j-1,n,m,prev,maxLen,cache);
	 	int right = dfs(matrix,i,j+1,n,m,prev,maxLen,cache);

		matrix[i][j] = prev;
		cache[i][j] = max(max(up,down),max(left,right)) + 1;

		return cache[i][j];
	}

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	if(!n) return 0;
    	int m = matrix[0].size();
    	int maxLen = 0;
    	vector<vector<int>> cache(n,vector<int>(m,0));
    	int value = INT_MIN;

    	for(int i = 0; i < n; ++i){
    		for(int j = 0; j < m ; ++j){
    			value = max(dfs(matrix,i,j,n,m,INT_MIN,0,cache),value);
    		}
    	}
    	return value;

    }
};

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<vector<int>> v = {
  	{3,4,5},
  	{3,2,6},
  	{2,2,1}};

  	std::vector<vector<int>> v2 = {
  {9,9,4},
  {6,6,8},
  {2,1,1}
  };
  	Solution s;
  	cout << s.longestIncreasingPath(v2);
	return 0;
}