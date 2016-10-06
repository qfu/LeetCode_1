#include <string>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {

public:
    string longestPalindrome(string s) {
    	int size = s.size();
    	if(!size || size > 1000) return "";
    	//2D DP array

    	//vector<vector<int>> dp(size,vector<int>(size,0));
    	 int dp[size][size];  
         memset(dp, 0, sizeof(dp));

    	//auto cmp = [](pair<int,int> a ,pair<int,int> b)->bool{ return (a.second - a.first) < (b.second - b.first); };

    	//priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
     	int max = 0;
 	 	int t = 0;
 	 	int h = 0;

 	 	for(int j = 0; j < size; ++j){
 	 		for(int i = j; i >=0; --i){
 	 			if(s[i] == s[j] && (j - i < 2 || dp[i+1][j-1])){
 	 				dp[i][j] = 1;
 	 				//pq.push(make_pair(i,j));
 	 				if(j - i > max){
 	 				    max = j -i;
 	 				    t = i;
 	 				    h = j;
 	 				}
 	 			}
 	 		}
 	 	}  	


 	 	//if(!pq.empty()){
 	 	//	pair<int,int> t = pq.top();
 	 	return s.substr(t,h-t+1);
 	 	//}	
		//return "";        
    }
};

int main(int argc, char** argv){
	Solution s;
	string test = "abcdfggfdcba";
	cout << s.longestPalindrome(test);		


	return 0;
}