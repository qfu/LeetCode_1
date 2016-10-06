#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
    	int m = word1.size();
    	int n = word2.size();

    	int dp[n+1][m+1];

    	memset(dp,0,sizeof(dp));
    	dp[0][0] = 0;

    	for(int i = 0; i <= n; ++i){
    		dp[i][0] = i;
    	}

		for(int j = 0; j <= n; ++j){
    		dp[0][j]= j ;
    	}

    	for(int i = 1 ; i <= n ; ++i){
    		for(int j = 1 ; j <= m; ++j){
    			if(word1[j-1] == word2[i-1]) dp[i][j] = dp[i-1][j-1];//min( (1+ min(dp[i-1][j],dp[i][j-1])), dp[i-1][j-1]);
    			else
					dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));  
				
				cout << dp[i][j] << " ";
    		}
    		cout << endl;
    	}
    	return dp[n][m];
    }
    int minDistance2(string word1, string word2) { 
        int m = word1.length(), n = word2.length();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 1; i <= m; i++)
            dp[i][0] = i;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;  
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
                    			cout << dp[i][j] << " ";

            }
            cout << endl;
        }
        return dp[m][n];
    }
};



int main(){
	Solution s;
	cout << s.minDistance("park","spake");
	cout << endl;
	cout << s.minDistance2("park","spake");
}
