#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	if(!s.size()) return vector<int>();

		unordered_map<string, int> map;
		for(string word: words) map[word]++;

		int ss = s.size(), ws = words.size(),len = words[0].size(),j=0;
		vector<int> index;

		for(int i = 0; i < ss- (ws*len)-1;++i){
			unordered_map<string, int> seen;
			j = 0;
			for(;j < ws;++j){
				string tmp = s.substr(i+j*len,len);
				if(map.find(tmp) != map.end()){
					seen[tmp]++;
					//duplicate 
					if(seen[tmp] > map[tmp]) break;
				}else break;
			}
			if(j == ws) index.push_back(i);
		}
		return index;
    }
};

int main(int argc, char ** argv){
	Solution s;
	string test = "barfoothefoobarman";
	vector<string> input = {"foo", "bar"};
	s.findSubstring(test,input);

}