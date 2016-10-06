#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;



class Solution {
public:

	bool backtrack(unordered_map<char,int>& map, string test,string result){
		for(auto it = map.begin(); it != map.end(); ++it){
			for(int i = it -> second; test[i] == '0';++i){
				cout << it -> second;
				cout << it -> first;
				test[i] = it -> first;
			}
		}
		cout << "test" << test << endl;
		cout << "result" << result <<endl;
		return test == result;
	}


    bool isMatch(string s, string p) {
    	if(p == ".*") return true;
    	if(p.find('.') == string::npos && p.find('*') == string::npos) return s == p;
    	else if(p.find('.') != string::npos && p.find('*') == string::npos){
    		for(int i = 0; i < p.size();++i){
    			if(p[i] == '.') p[i] = s[i];
    		}
    		return p == s;
    	}else if(p.find('.') == string::npos && p.find('*') != string::npos){
    		//find the position of * and then use backtrack 
    		unordered_map<char,int> map;
    		for(int i =0; i < p.size(); ++i){
    			if(p[i] == '*'){
    				int label = s.find_first_of(p[i-1]);
    				if (label!=string::npos) 
    					map[p[i-1]] = label;
    			}
    		}
    		//initilize test string 
    		string test(s.size(),'0');
    		int index = 0;
    		for(int i = 0; i < s.size(); ++i){
    			if(map.find(s[i]) == map.end()) test[i] = s[i];
    		}

    		return backtrack(map,test,s);

    		//next step is to fill in the bank this is the part where backtrack comes into play


    	}else{
    		// * . coexists
    		return true;

    	}
    }


    bool isMatch2(string s, string p) {
	      	int m = s.length(), n = p.length(); 
	        vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
	        dp[0][0] = true;
	        for (int i = 0; i <= m; i++)
	            for (int j = 1; j <= n; j++)
	                if (p[j - 1] == '*'){
	                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
	                    cout << "dp[" << i << "]["<<j<<"] = " << dp[i][j] << endl;
	                }
	                else{
	                	dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
	                	cout << "dp[" << i << "]["<<j<<"] = " << dp[i][j] << endl;

	                }
	        return dp[m][n];
    }

};

int main(){
	Solution s;
	cout << s.isMatch2("aab","c*a*b");

}