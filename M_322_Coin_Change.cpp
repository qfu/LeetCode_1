#include <iostream>
#include <vector>
#include <climits>

using namespace std;



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        if(!size) return -1;
        if(amount == 0) return 0;

        vector<long> dp(amount+1,INT_MAX);
        dp[0] = 0;

        int t;
        for(t = 0; t < size;++t){
        	if(coins[t] <= amount) break;
        }
        if(t == size) return -1;


        for (int i = 0; i < size; ++i){
        	if(coins[i] <= amount)
        		dp[coins[i]] = 1;
        }

        for(int j = 1; j <= amount;++j){
        	for(int i = 0; i < size;++i){
        		if(j - coins[i] > 0){
        			dp[j] = min(dp[j - coins[i]]+1,dp[j]);
        		}
        	}

        	//cout << "sum " << j << "has " <<dp[j] << " number of coin"<<endl;
        }
   
        return (dp[amount]==INT_MAX)?-1:dp[amount];
 
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	std::vector<int> v = {4};

	cout << s.coinChange(v,11);
	return 0;
}