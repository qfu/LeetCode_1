#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int size = nums.size();

    	if(!size) return 0;

    	int sum = 0;
    	int maxLength = INT_MAX;
    	for(int i = 0; i < size; ++i){
    		sum += nums[i];
    		for(int j = i+1; j < size; ++j){
    			sum += nums[j];
    			if(sum >= 7){
    				maxLength = min(maxLength, j - i + 1);
    				break;
    			} 
    		}
    		sum = 0;
    	}
    	return (maxLength == INT_MAX)?0:maxLength;
        
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	std::vector<int> v = {2,3,1};
	cout << s.minSubArrayLen(7,v);
	return 0;
}