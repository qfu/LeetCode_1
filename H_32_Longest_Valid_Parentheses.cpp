#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
    	int size = s.size();
    	vector<int> dp(size,0);

    	int maxlen = 0;
    	for(int i = 1; i < size; ++i){
    		if(s[i] == ')'){
    			if(s[i-1] == '('){
    				dp[i] = (i-2 >=0)? (dp[i-2]+2):2;
    				maxlen = max(maxlen,dp[i]);
    			}else{
    				// ))
    				if((i - dp[i-1] - 1) >= 0 && s[i-dp[i-1]-1] == '('){
    					if(i-2-dp[i-1] >= 0)
    						dp[i] = dp[i-1] + 2 + dp[i-2-dp[i-1]];
    					else 
    						dp[i] = dp[i-1] + 2;
    					maxlen = max(maxlen,dp[i]);
    				}
    				//else doesn't form the increase the valid pair
    			}
    		}
    		else{
    			dp[i] = 0;
    		}
    	}

    	for(int c : dp){
    		cout << c << " ";
    	}

    	return maxlen;
    }
};

int main(int argc, char const *argv[]){
	Solution s;
	cout << s.longestValidParentheses("()(())");
	/* code */
	return 0;
}