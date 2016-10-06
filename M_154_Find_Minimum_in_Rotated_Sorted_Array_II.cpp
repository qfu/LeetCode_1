#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
	int binarySearch(vector<int>& nums, int start, int end){
		
		if(start < end){
			if(nums[start] < nums[end]){
				 return nums[start];
			}

			/*
			if(end - start == 1){
				return min(nums[end],nums[start]);
			}*/

			int mid = start + ((end - start) >> 1);

			if(nums[start] < nums[mid])
				return binarySearch(nums,mid+1,end);
			else if(nums[start] > nums[mid])
				return binarySearch(nums,start,mid);
			else
				return min(binarySearch(nums,mid+1,end),binarySearch(nums,start,mid));
		}
		return nums[start];
	}

public:
    int findMin(vector<int>& nums) {
        

      cout << binarySearch(nums,0,nums.size()-1);
      return 1;
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	std::vector<int> v = {3,3,1};
	Solution s;
	s.findMin(v);
	return 0;
}