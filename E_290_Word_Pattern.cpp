#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
   bool wordPattern(string pattern, string str) {
    	vector<string> v = delimiter(str);
        if (pattern == str || v.size() != pattern.size()) return false;
    	unordered_map<char,string> mymap;
    	unordered_map<string,char> strmap;
    	bool check = true;

    	for(int i =0 ; i < pattern.size(); ++i){
    		if(mymap.find(pattern[i]) != mymap.end() || strmap.find(v[i]) != strmap.end()){
    			check  &= mymap[pattern[i]] == v[i];
    			check  &= strmap[v[i]] == pattern[i];
    		}
    		else{
    			mymap[pattern[i]] = v[i];
    			strmap[v[i]] = pattern[i];
    		}
    	}

        return check;
    }

    vector<string> delimiter(string s){
    	string delimiter = " ";
    	vector<string> vec;
    	size_t pos = 0;

    	while((pos= s.find(delimiter)) != string::npos){
    		vec.push_back(s.substr(0,pos));
    		s.erase(0,pos+1);
    	}
    	vec.push_back(s);
    	return vec;
    }

};


int main(){
	Solution s;

	cout << s.wordPattern("aaaa", "dog cat cat dog");

}