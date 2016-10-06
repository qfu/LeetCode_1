#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <set>
#include <algorithm>
using namespace std;





bool operator==( unordered_map<char,int>& a, unordered_map<char,int>& b){
	for(auto it = a.begin(); it != a.end(); ++it){
		if(a[it->first] != b[it->first]) return false;
	}
	return true;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	unordered_map<string,multiset<string>> map;
    	vector<vector<string>> matrix;

    	for(string s : strs){
    		string t = s;
    		sort(t.begin(),t.end());
    		map[t].insert(s); 
    	}

    	for(auto & x : map){
    		vector<string> anagram(x.second.begin(),x.second.end());
    		matrix.push_back(anagram);
    	}
    	return matrix;

    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};

	vector<vector<string>> test = s.groupAnagrams(v);
	for_each(test.begin(),test.end(),[](const vector<string>& v){for(string s : v) cout << s <<" ";
		cout << endl;
	});


	/* code */
	return 0;
}