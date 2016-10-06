#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	//Unknown if l1 == l2
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        vector<vector<bool>> dp(l1+1,vector<bool>(l2+1,false));
        //l1 * l2

        //initialize the base case to be true
        dp[0][0] = true;
        int i1 = 0;
        int i2 = 0;

        for(int j = 0; j < l3; ++j){
        	 if (i1 < l1 && s3[j] == s1[i1]) dp[i1+1][i2] = dp[i1][i2] && s3[j++] == s1[i1++];
        
        	 if (i2 < l2) dp[i1][i2+1] = dp[i1][i2];
        
        	
        }
        return dp[l1-1][l2-1];
    }
   bool isInterleave2(string s1, string s2, string s3) {
    
    if(s3.length() != s1.length() + s2.length())
        return false;
    
    bool table[s1.length()+1][s2.length()+1];
    
    for(int i=0; i<s1.length()+1; i++)
        for(int j=0; j< s2.length()+1; j++){
            if(i==0 && j==0)
                table[i][j] = true;
            else if(i == 0)
                table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
            else if(j == 0)
                table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
            else
                table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
        }

        for(int i = 0 ; i < s1.length()+1; ++i){
        	for(int j = 0; j < s2.length()+1;++j){
        		cout<< table[i][j] << " ";
        	}
        	cout << endl;
        }
    	return table[s1.length()][s2.length()];
	}
};



int main(){
	Solution s;
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	string s4 = "aadbbbaccc";

	s.isInterleave2(s1,s2,s3);
	//cout << "Flase" << s.isInterleave(s1,s2,s4);

}