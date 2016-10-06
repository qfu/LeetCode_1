#include <unordered_set>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	bool combination(vector<string>& vec, string s, int start, int size, string result){
		//find all possible combinations
		if(result.size() >= s.size()){
			//return combination
			return result == s;
		}

		for(int i = 0; i < size; ++i){
			int temp = result.size();
			result += vec[i];
			if (combination(vec,s,start+1,size,result)) return true;
			result.resize(temp);		
		}
		return false;
	}



    bool wordBreak(string s, unordered_set<string>& wordDict) {
    	int size = wordDict.size();
    	if(!size) return false;
    	std::vector<string> v;
    	string result;


    	for(auto it = wordDict.begin(); it != wordDict.end(); ++it){
    		//find all possible substrings 
    		if(s.find(*it) != string::npos) v.push_back(*it);
    	}

	    return combination(v,s,0,v.size(),result);
        	
    }
};


int main(int argc, char ** argv){

	string test = "leetcode";

	unordered_set<string> dict = {"lee","code","le","tcod","e"};

	Solution s;
	
	
	//std::vector<string> v = {"lee","code","le","etcod","de"};

	//string result;
	//cout << s.combination(v,test,0,v.size(),result);

	//Test 1
	cout << s.wordBreak(test,dict);




	return 0;
}