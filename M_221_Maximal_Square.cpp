#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();	
        int m = matrix[0].size();

        if(!n) return 0;

        //Dynamic Programming Matrix
        int result = 0;
        std::vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i = 0; i < n; ++i){
        	for(int j = 0; j < m; ++j){
        		if(i == 0 || j ==0 )result = max(result, (matrix[i][j] - '0'));
        		if(matrix[i][j] == '1'){
        			dp[i][j] = 1;
        		}
        		else
        			dp[i][j] = 0;
        	}
        }
       for(int i = 1; i < n; ++i){
        	for(int j = 1; j < m; ++j){
        	
        	 		//boundary is not going to work
        	 		//stuck on the thought of parameters 
        	 		//trying to think of th width
        	 	if(dp[i][j])dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));

        	 	
        	 	result = (dp[i][j] > result) ? dp[i][j] : result; 
        	}
        }
        return result * result;
    }
};


int main(){
	std::vector<char> v1 = {'1','1','0'};
	std::vector<char> v2 = {'1','1','1'};
	std::vector<char> v3 = {'1','1','1'};

	std::vector<vector<char>> test = {v1,v2,v3};

	Solution s;
	cout << s.maximalSquare(test);
}