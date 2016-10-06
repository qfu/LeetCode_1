#include <vector>
#include <string>
#include <iostream>
#include <set>
using namespace std;

class Solution {
private:
	void dfs(string s,int index, int left_remove, int right_remove,int pair,string path,set<string>& res){
		//always go to the end
		if(index == s.size()){
			if(!left_remove && !right_remove && !pair){
				res.insert(path);
			}
			return;
		}

		if(s[index] != '(' && s[index] != ')'){
			dfs(s,index+1,left_remove,right_remove,pair,path+s[index],res);
		}else{
			if(s[index] == '('){
				if(left_remove>0) dfs(s,index+1,left_remove-1,right_remove,pair,path,res);
				//for normal case and for backtrack
				dfs(s,index+1,left_remove,right_remove,pair+1,path+s[index],res);
			}

			if(s[index] == ')'){
				if(right_remove>0) dfs(s,index+1,left_remove,right_remove-1,pair,path,res);
				//for normal and backtrakc case make sure ( is existed
				if(pair > 0) dfs(s,index+1,left_remove,right_remove,pair-1,path+s[index],res);
			}

		}

	}


public:
    vector<string> removeInvalidParentheses(string s) {
    	int size = s.size();
    	if(!size) return vector<string>();

    	int left_remove = 0, right_remove = 0;
    	for(char c : s){
    		if( c == '('){
    			left_remove++;
    		}

    		if(c == ')'){
    			if(left_remove > 0) left_remove--;
    			else right_remove++;
    		}
    	}
    	set<string> res;
    	string path = "";

    	dfs(s,0,left_remove,right_remove,0,path,res);
    	for(string t : res) cout << t << " ";
    	return vector<string>(res.begin(),res.end());
    }
};

int main(int argc, char const *argv[])
{
	string s = "()()())";
	Solution test;
	test.removeInvalidParentheses(s);


	return 0;
}