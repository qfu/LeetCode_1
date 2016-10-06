#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	int binarySearch(vector<int>& nums, int start, int end, int target){
		//if = then must add -1 or +1
		while(start <= end){
			int mid = start + ((end - start)>> 1);
			if(nums[mid] == target) return mid;

			if(nums[mid] > target) end = mid-1;
			else if(nums[mid]  < target) start = mid+1;
		}
		return -1;
	}

public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	int size = nums.size();
    	if(!size) return {-1,-1};

    	int result = binarySearch(nums,0,size-1,target);
    	cout << result;

    	int left = result, right = result;
    	while(left - 1 >= 0 && nums[left-1] == nums[left]) left--;

       	while(right + 1 < size && nums[right+1] == nums[right]) right++;

       	return {left,right};
    	
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<int> v = {0,0,1,1,1,4,5,5};

	Solution s;
	vector<int> r = s.searchRange(v,2);
	cout << r[0] << " ," << r[1] << endl;
	return 0;
}