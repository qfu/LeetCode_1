#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
	bool isPalindrome(string s){
		string t = s;
		reverse(s.begin(),s.end());
		return s == t;
	}

	void backtrack(vector<vector<string>>& vec, vector<string>& step, string ss){
		int n = ss.size();
		if(!n){
			vec.push_back(step);
			return;
		}


		for(int j = 1; j <= n; ++j){
			string sub = ss.substr(0,j);
			if (isPalindrome(sub)){
				step.push_back(sub);
				backtrack(vec,step,ss.substr(j));
				step.pop_back();
			}
		}
		return;
	
	}

public:

	vector<vector<string>> partition(string s) {
		vector<vector<string>> vec;
		vector<string> step;
		int size = s.size();

		if(!size) return vec;

		backtrack(vec,step,s);

		/*
		for(auto & a : vec){
			for(auto & b : a){
				cout <<b << " ";
			}
			cout << endl;
		}*/
		return vec;
        
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	string test = "aabaa";
	s.partition(test);

	return 0;
}