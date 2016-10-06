#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
    	if(!s.size() && !t.size()) return true;
    	if(!s.size() || !t.size()) return false;
    	unordered_map<char,int> map;
    	for(char c: s){
    		map[c]++;
    	}
    	for(char c: t){
    		if(map.find(c) != map.end())
    			map[c]--;
    		else 
    			return false;
    	}

    	for(auto it = map.begin(); it != map.end();++it){
    		if(it->second) return false;
    	}
    	return true;
    }
};


int main(){

	Solution s;
	string a = "abc";
	string b = "cbc";
	cout << s.isAnagram(a,b);

}