#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if(!size) return 0;

        int dp[size+1];
        memset(dp,0,sizeof(dp));

        dp[0] = 1;

        for(int i = 1; i <= size;++i){
            if(i == 1){
                dp[1] = (s[i-1] >= '1')?dp[0]:0;
            }
        	else if(((s[i-2] == '2' && s[i-1] <= '6') || s[i-2] == '1') && s[i-1] != '0') dp[i] = dp[i-1]+dp[i-2];
        	else if(((s[i-2] == '2' && s[i-1] <= '6') || s[i-2] == '1') && s[i-1] == '0') dp[i] = dp[i-2];
        	else if(s[i-1] == '0') dp[i] = 0;
        	else dp[i] = dp[i-1];
 
        }
        return dp[size];

    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	string test = "1394";
	cout << s.numDecodings(test);
	return 0;
}