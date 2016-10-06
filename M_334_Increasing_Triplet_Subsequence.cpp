#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    	int n = nums.size();
    	int dp[n];

    	//not working for 1
    	//cannnot fillin 1
    	std::fill(array, array+sizeof(array)/anInt, 0);
    	memset(dp,1,sizeof(dp));
    	//

    	for(int i = 1 ; i < n;++i){
    		for(int j = 0; j < i; ++j){
    			if(nums[j] < nums[i]){
    				//dp[j] make sure that 5 4 7
    				dp[i] = max(dp[i],dp[j]+1);	
    			}
    		}
    		if (dp[i] == 3) return true;
    	}
    	return false;

    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}