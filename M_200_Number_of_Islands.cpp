#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
	bool DFS(vector<vector<char>>& grid, int i, int j, int n, int m){
		if(i < 0 || j < 0 || i >= n || j >= m)
			return false; 
		if(grid[i][j] == '1'){
			grid[i][j] = 'B';
			if (DFS(grid,i-1,j,n,m) ||DFS(grid,i+1,j,n,m) || DFS(grid,i,j-1,n,m) || DFS(grid,i,j+1,n,m))
				return true;
		}
		return false;

	}

public:
    int numIslands(vector<vector<char>>& grid) {
    	int n = grid.size();
    	int m = grid[0].size();

    	int count = 0;
    	for (int i = 0; i < n; ++i){
    		for (int j = 0; j < m; ++j){
    			if (grid[i][j] == '1'){
    				 DFS(grid,i,j,n,m);
    				 count += 1;
    			}	
    		}
    	}
/*
    	for (int i = 0; i < n; ++i){
    		for (int j = 0; j < m; ++j){
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}*/


    	return count;

    }

};



int main(int argc, char const *argv[])
{
	/* code */


	std::vector<char> v1 = {'1','1','0','1','0'};
	std::vector<char> v2 = {'1','1','0','1','0'};
	std::vector<char> v3 = {'1','1','0','0','0'};
	std::vector<char> v4 = {'0','0','0','1','0'};
	
	std::vector<vector<char>> v = {v1,v2,v3,v4};

    Solution s;
    cout << s.numIslands(v);


	return 0;
}