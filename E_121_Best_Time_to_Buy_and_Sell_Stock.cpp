#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
         if (prices.size() < 2) return 0;

        int buy = prices[0];
        int sold = buy;
        int profit = 0;
        for(int i =1; i < prices.size();++i){
        	if(prices[i] < prices[i-1] && prices[i]<buy){
        	 	buy = prices[i];
        	 	sold = buy;
        	}
        	else if (prices[i] > prices[i-1]) sold = prices[i];

        	if (sold - buy > profit) profit = sold- buy;
        }
        return profit;
    }
};

int main(){

}