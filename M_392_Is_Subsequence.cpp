#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        int dp[n+1][m+1];
       	memset(dp,0,sizeof(dp));

       	for(int i = 0; i <= m; ++i) dp[0][i] = 1;

       	for(int i = 1; i <= n; ++i){
       		for (int j = 1; j <= m; ++j){
       			if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
       			else dp[i][j] = dp[i][j-1];
       		}
       	}
       	return dp[n][m];

    }

    bool isSubsequence(string s, string t){
    	int n = s.size();
    	if(!n) return true;
    	int m = t.size();
    	if(!m) return false;

    	int si = 0;
    	for(int i = 0; i < n && i < m; ++i){
    		if(s[si] == t[i]) si++;
    	}
    	return si == n;
    }
};

int main(int argc, char ** argv){


	return 0;
}