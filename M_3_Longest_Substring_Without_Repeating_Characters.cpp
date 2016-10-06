#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(!size) return 0;

        vector<int> dp(size,0);
        unordered_map<char,int> map;

        int p = 1;
        int m = 0;
        dp[0] = 1;
        map[s[0]] = 1;
        for (int i = 1; i < size; ++i){
      

        	if(s[i] != s[i-1] && !map[s[i]]) dp[i] = max(dp[i],dp[i-1]+1);
        	else if(s[i] != s[i-1] && map[s[i]]){
        		p = max(dp[i-1],p);
        		//because I cannot include the previous occurance
        		// what is fucked up is the first value

        		//not necessary start from the top 
        		if(map[s[i]] == 1 && s.find_first_of(s[i]) == 0){
        			 m = max(1,m);
        			 dp[i] = dp[i-1];
        		}
        		else{
        			 m = max(map[s[i]],m);
        		 	 dp[i] = dp[i-1]- dp[m]+1;
        		}
        	}
        	//if(i == 4) cout << dp[i] << " 1";
        	p = max(dp[i],p);
        	map[s[i]] = i;
        }
        return p;
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	string t1 = "abcabcbb";
	string t2 = "bbbbb";
	string t3 = "pwwkew";
	string t4 = "ckilbkd";
	string t5 = "dcdf";

	Solution s;
	cout << s.lengthOfLongestSubstring(t1);

	cout << s.lengthOfLongestSubstring(t2);
	cout << s.lengthOfLongestSubstring(t3);
	cout << s.lengthOfLongestSubstring(t4);
	cout << s.lengthOfLongestSubstring(t5);

	return 0;
}