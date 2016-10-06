#include <string>
#include <iostream>
#include <numeric>      // std::accumulate


using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
    	int n = t.size();
    	int m = s.size();

    	if(!n || !m) return 0;

    	int dp[n][m];

    	memset(dp,0,sizeof (dp));

    	for(int i = 0; i < n; ++i){
    		for(int j = 0; j < m; ++j){
    			if( i == 0){
    				dp[i][j] = (s[j] == t[i]);
    			}
    			else if(j == 0){
    				dp[i][j] = dp[i][j] && (s[j] == t[i]);
    			}
    			else if(i != 0 && j != 0){
    				//cout <<accumulate(dp[i-1],dp[i-1]+ j-1,0);
    				if (s[j] == t[i]) dp[i][j] = accumulate(dp[i-1],dp[i-1]+j,0); 
    			}
    		}
    		cout << endl;
    	}
        
        return accumulate(dp[n-1],dp[n-1]+m,0);
    }
};

int main(){
	string s = "rabbbit", t = "rabbit";

	Solution x;
	cout << x.numDistinct(s,t);


}