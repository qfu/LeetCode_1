#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	int size = nums.size();
    	if(!size) return 0;

    	int dp[size];
    	memset(dp,-100,sizeof(dp));

    	int product = 1;
    	for(int i = 0; i < size; ++i){
    		for(int j = i; j >= 0; j--){
    			product *= nums[j];
    			dp[i] = max(dp[i],product);
    		}
    		product = 1;
    	}
        return *max_element(dp,dp+size);
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<int> v = {-2};
	Solution s;
	cout << s.maxProduct(v);
	return 0;
}