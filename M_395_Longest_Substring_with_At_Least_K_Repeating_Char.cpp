#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        if(!s.size()) return 0;

       	unordered_map<char,int> map;
    	for(char c : s)	map[c]++;

    	int split = 0;
    	while(split < s.size() && map[s[split]] >= k) split++;

    	if(split == s.size()) return s.size();

    	int left = longestSubstring(s.substr(0,split),k);
    	int right = longestSubstring(s.substr(split+1),k);

    	return max(left,right);
    }
};


int main(int argc, char const *argv[]){
	/* code */
	string test = "aaabb";

	Solution s;
	cout << s.longestSubstring(test,3);

	return 0;
}
