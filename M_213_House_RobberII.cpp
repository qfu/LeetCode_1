#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
    	int size = nums.size();
    	if (!size) return 0;

    	vector<int> dp(size+1,0);
    	vector<int> location(size+1,0);

    	int restart;
    	int last = 0;

    	dp[1] = nums[0];
    	location[1] = 1;
    	for(int i = 2; i <= size; ++i){
    		if(dp[i-1] >(dp[i-2] + nums[i-1]) && location[i-1] == 1){
    			location[i] = 1;
    		}else if (dp[i-1] < (dp[i-2] + nums[i-1]) && location[i-2] == 1){
    			location[i] = 1;
    		}else{
    			location[i] = 0;
    		}
    		if(i == size){
    			last = ((dp[i-2] + nums[i-1])> dp[i-1]) ? 1 : last;
    		}

    		dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
    	}
    	
    	if(location[size] == 1 && last == 1){
    		for(int j = 1; j <= size; ++j){
    			if(location[j] == 0){
    				restart = j;
    			}
    		}
    	}else{
    		return dp[size];
    	}

  		for(int i = restart+1; i <= size; ++i){
  			if(i == restart + 1){
  				dp[i] = max(dp[i-1],nums[i-1]);
  			}
    		else dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
    	}

	
    	for(int x : location){
    		cout << x << " ";
    	}	

    	cout << endl;
    	for(int y : dp){
    		cout << y << " ";
    	}

    	return dp[size];
        
    }


    int rob2(vector<int>& nums)
	{
    	if(nums.size() == 0)
        	return 0;
    	if(nums.size() == 1)
        	return nums[0];
    
    	int pre1 = 0, cur1 = 0;
    	for(int i = 0; i < nums.size() - 1; ++ i)
    	{
        	int temp = pre1;
        	pre1 = cur1;
        	cur1 = max(temp + nums[i], pre1);
    	}
    
    	int pre2 = 0, cur2 = 0;
    	for(int i = 1; i < nums.size(); ++ i)
    	{
        	int temp = pre2;
        	pre2 = cur2;
        	cur2 = max(temp + nums[i], pre2);
    	}
    
    	return max(cur1, cur2);
	}
};

int main(int argc, char const *argv[])
{
	/* code */

	std::vector<int> v = {2,1,1,2};
	Solution s;
	cout << s.rob(v);
	return 0;
}