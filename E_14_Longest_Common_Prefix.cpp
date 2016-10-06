#include <vector>
#include <string>
#include <iostream>
using namespace std;g


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        
       string prefix = "";

        int size = strs.size();
        if(!size) return prefix;
        int length = strs[0].size();
        int index = 0;
        string holder = strs[0];
        for(int j = 0; j < length; ++j){
        	
	        for(int i = 1; i < size; ++i){
	            if(strs[i][j] == holder[j])
	                continue;
	            else 
	                return prefix;
	        }
	        prefix += holder[j];
		}        
        
        return prefix;
        
    }
};


int main(int argc, char ** argv){
	Solution s;
	string a = "abc";
	string b = "abcde";
	string c = "abcfa";

	std::vector<string> v = {a,b,c};

	cout << s.longestCommonPrefix(v);


}