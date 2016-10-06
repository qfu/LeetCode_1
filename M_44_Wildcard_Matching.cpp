#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
    	int input = s.size();
    	int match = p.size();

    	int dp[input+1][match+1];
    	memset(dp,0,sizeof(dp));
    	dp[0][0] = 1;

    	for(int i = 1; i <= input; ++i){
    		for(int j = 1; j <= match; ++j){
    			if(i == 1 && j == 1){
    				if(s[i-1] == p[j-1] || p[i-1] == '?' || p[i-1] == '*') dp[i][j] = dp[i-1][j-1];
    			}else if(i == 1 && j != 1){
    				if(p[j-1] == '*' && dp[i][j-1]) dp[i][j] = dp[i][j-1];
    				if(p[j-2] == '*' && ((p[j-1] == s[i-1])|| (p[j-1] == '?'))) dp[i][j] = dp[i][j-2];

    			}else if(i != 1 && j == 1){
    				if(p[j-1] == '*' && dp[i-1][j]) dp[i][j] = dp[i-1][j];
    			}else{
    				if((p[j-1] == s[i-1])|| (p[j-1] == '?')  || (p[j-1] == '*')) dp[i][j] = dp[i-1][j-1];
    			}
    			//cout << dp[i][j] << endl;
    		}
    	}
    	return dp[input][match];
    }

	bool isMatch2(string s, string p) {
    	int input = s.size();
    	int match = p.size();

    	int dp[input+1][match+1];
    	memset(dp,0,sizeof(dp));
    	dp[0][0] = 1;

    	for(int i = 0; i <= input; ++i){
    		for(int j = 1; j <= match; ++j){
    			if(p[j-1] =='*')
    				dp[i][j] =  (i > 0 && dp[i-1][j]) || dp[i][j-1];
    			else
    				dp[i][j] =  (i > 0) && ((p[j-1] == s[i-1])|| (p[j-1] == '?'))&& dp[i-1][j-1];
    		}
    	}
    	return dp[input][match];
    }

};

int main(int argc, char const *argv[]){
		
	Solution s;
	
	cout << s.isMatch2("aa","a");
    cout << s.isMatch2("aa","aa");
    cout << s.isMatch2("aaa","aa");
    cout << s.isMatch2("aa", "*");
    cout << s.isMatch2("aa", "a*"); 
    cout << s.isMatch2("ab", "?*");
    cout << s.isMatch2("aab", "c*a*b"); 

	return 0;
}