#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 1) return 0;

        int leftMax = 0;
        int runMax = 0;
        int profit = 0;

        int start = 0;
        for(int i = 1; i < size; ++i){
        	for(int j = i-1; j >= start; --j){
        		if(prices[j] < prices[i]) runMax = max(runMax,prices[i]-prices[j]);
        	}
        	if(runMax == leftMax){
        		profit += leftMax;
        		leftMax = 0;
        		runMax = 0;
        		start = i;
        	}
        	else leftMax = max(leftMax,runMax);
        }
        profit += leftMax;
        return profit;

    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	std::vector<int> v = {4,3,9,10,7,12,8,7};
	cout << s.maxProfit(v);
	return 0;
}