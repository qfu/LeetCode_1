#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
    	int size = nums.size();

    	if(!size) return 0;

    	vector<vector<int>> dp(size,vector<int>(size,0));

    	int max = 0;
    	int ulti = 0;
    	for(int i = 0; i < size; ++i){
    		for(int j = i ; j < size;++j){
    			//boundary condition 


    			//the most correct algorithm should be count the smallest 
    			//to the start index and compare into to the previous value 

    			if(j == i) dp[i][j] = 0;
    			else dp[i][j] = dp[i][j-1] + (nums[j] >= nums[j-1]);
    			cout << dp[i][j] << " ";   

    			if(j == size-1) ulti = (dp[i][j] >= ulti)? dp[i][j] : ulti;
    		}
    		cout << endl;
   
    	}
    	return ulti+1;
    }
};



int main(int argc, char const *argv[])
{
	std::vector<int> v1 = {1,3,6,7,9,4,10,5,6};
	std::vector<int> v2 = {10, 9, 2, 5, 3, 7, 101, 18};
	Solution s;
	cout << s.lengthOfLIS(v2);

	return 0;
}