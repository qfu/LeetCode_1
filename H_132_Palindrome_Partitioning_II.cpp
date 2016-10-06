#include <string>
#include <iostream>
using namespace std;

class Solution {

	bool isPalindrome(string s){
		string t = s;
		reverse(s.begin(),s.end());
		return s == t;
	}
public:
    int minCut(string s) {
        int size = s.size();
        if(!size) return 0;

        int dp[size+1];
        memset(dp,0,sizeof(dp));
        dp[0] = -1;
        dp[1] = 0;
        bool flag = false;
        for(int i = 1; i < size;++i){
        	for(int j = i-1; j >= 0; --j){
        		if(isPalindrome(s.substr(j,i-j+1))){
        			 cout << s.substr(j,i-j+1) << endl;
        			 dp[i+1] = min(dp[j]+1, max(dp[i+1],dp[j]+1));
        			 flag = true;
        		}
        	}
        	if(!flag) dp[i+1] = dp[i]+1;
        	else dp[i+1] = min(dp[i+1],dp[i]+1);
        	flag = false;
        }
        for(int i : dp){
        	cout << i << " ";
        }
        cout << endl;

       	return dp[size];
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	string test = "adaba";
	cout << s.minCut(test);
	return 0;
}