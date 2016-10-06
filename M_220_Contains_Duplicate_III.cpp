#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
  		int size = nums.size();
  		if(!size) return false;
        int l = min(k,size-1);

  		for(int i = l; i < size; ++i){
  			for(int j = (i-l); j < i;++j){
  				if(abs(nums[i] - nums[j]) <= t){
  					//handle the case of overflow
  				   if(abs((long)nums[i] - (long)nums[j]) <= t) return true;
  				   //return true;
  				} 
  			}
  		}
  		return false;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}