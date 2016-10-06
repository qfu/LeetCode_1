#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

   		// 

	        
        if(obstacleGrid[0][0] == 1) return 0; 
	
		int i,j;
		int x = obstacleGrid.size(); 
		int y = obstacleGrid[0].size();
		for(i = 0; i < obstacleGrid.size();++i){
			if(j == 0 && obstacleGrid[i][j] == 0)
				obstacleGrid[i][j] = 1;
			else if(j == 0 && obstacleGrid[i][j] == 1){ 
				obstacleGrid[i][j] = 0;
				if(i+1 < obstacleGrid.size()) obstacleGrid[i+1][j] = 1;
			}


			for (j = 0; j < obstacleGrid[0].size(); ++j){
					if(i == 0 && obstacleGrid[i][j] == 0) obstacleGrid[i][j] = 1 ;
					else if(i == 0 && obstacleGrid[i][j] == 1){ 
						obstacleGrid[i][j] = 0;
						if(j+1 < obstacleGrid[0].size()) obstacleGrid[i][j+1] = 1;
					}
					else if (i != 0 && j!= 0 && obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
					else obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j];
			}
			j = 0;
		}
		return obstacleGrid[x-1][y-1];
    }

	int uniquePathsWithObstacles_working(vector<vector<int>>& obstacleGrid) {
	    int row = obstacleGrid.size();
	    int col = obstacleGrid[0].size();
	    vector<int> dp(col,0);
	    dp[0]=1;
	    for(int i=0;i<row;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
	            if(obstacleGrid[i][j])
	                dp[j]=0;
	            else if (j>0)
	                dp[j] += dp[j-1];
	        }
	    }
	    return dp[col-1];
	}

};


int main(){
	vector<int> v1 = {0,0,0};
	vector<int> v2 = {0,1,0};
	vector<int> v3 = {0,0,0};

	vector<vector<int>> v = {v1,v2,v3};
	cout << Solution::uniquePathsWithObstacles(v);


}