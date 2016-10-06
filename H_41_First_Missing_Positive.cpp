#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	int mi = INT_MAX;
    	int ma = INT_MIN;
        unordered_map<int,int> map;
        for(int i : nums){
        	map[i]++;
        }

        for(int i : nums){
        	if(i > 1 && !map[i-1])
        		mi = min(mi,i-1);
        	ma = max(ma,i);
        }
        return (mi == INT_MAX)? ma+1 : mi;
    }

    int firstMissingPositive2(vector<int>& nums){
    	int i = 0, n = nums.size();
    	while(i < n){
    		if(nums[i] >= 0 && nums[i] < n && nums[nums[i]] != nums[i])
    			swap(nums[i],nums[nums[i]]);
    		else 
    			i++;
    	}

    	int k = 1;

    	while(k < n && nums[k] == k) k++;
    	if(n ==0 || k < n) return k;
    	else return nums[0] == k? k+1:k;

    	return 0;
	
    }


};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	std::vector<int> v = {0,1,2};

	cout << s.firstMissingPositive2(v);
	return 0;
}