#include <vector>
#include <iostream>
using namespace std;
class Solution {
private:

	bool binarySearch(vector<int>& nums, int start, int end, int target){
		while(start <= end){	
			int mid = start + ( (end - start) >>1);

			if(nums[mid] == target) return true;

			if(nums[mid] > nums[end]){
				//left part is sorted
				if(target < nums[mid] && target >= nums[start])
					end = mid -1
				else 
					start = mid + 1;

			}else if(num[mid] < nums[end]){
				if(target > nums[mid] && target <= nums[end])
					start = mid + 1;
				else end = mid -1;

			}else{
				//because it can either go to left or right
				//can not determine so we have to decrease
				//two instances of sth exits
				end--;
			}
		}
		return false;

	}


public:
    bool search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<int> v = {1,3,1,1,1};
	Solution s;

	cout << s.search(v,3);
	return 0;
}