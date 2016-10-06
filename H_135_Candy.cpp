#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(!n) return 0;

        int candies[n];
        memset(candies,0,sizeof(candies));

        candies[0] = 1;
        for (int i = 1; i < n; ++i){
        	if(ratings[i] > ratings[i-1])
        		candies[i] = candies[i-1] + 1;
        	else if (ratings[i] < ratings[i-1]){
      			if (candies[i-1]-1 > 1){
      			 	candies[i] = min(candies[i-1]-1,1);
      			}
      			else{
      				candies[i-1] += 1;
      				candies[i] = min(candies[i-1]-1,1);
      			}
        	}
        	else{
        		candies[i] = candies[i-1];
        	}
        }

        for(int i : candies){
        	cout << i << " ";
        }
        return accumulate(candies,candies+n,0);

    }

    int candy2(vector<int>& ratings){
        int size = ratings.size();

        if(size <= 1) return size;

        vector<int> num(size,1);

        for(int i = 1; i < size; ++i){
           if (ratings[i] > ratings[i-1])
              num[i] = num[i-1]+1;
        }
        //if descending everything will stay 1
        //reading from right already guranttee minimum
        for(int i = size-1; i > 0;--i){
            if(ratings[i-1] > ratings[i])
               num[i-1] = max(num[i]+1, num[i-1]);
        }

        return accumulate(num,num+size,0);

    }


};



int main(int argc, char const *argv[])
{
	
	std::vector<int> v = {2,2,3,4,5,6,4,3,2};
	Solution s;
	cout << s.candy(v);
	return 0;
}