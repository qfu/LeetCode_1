#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int binarySearch(vector<int>& nums,int start, int end, int target){
		if(start <= end){
			int mid = (start + end )/2;


			if(nums[mid] == target) return mid;


			// which means the rotate parts are sorted
			if(nums[mid] < target && target < nums[end]) return binarySearch(nums,mid +1,end,target);
			else if (nums[mid] > target && target > nums[start])return binarySearch(nums,start,mid-1,target);
			else{
				int value = binarySearch(nums,mid +1,end,target);
				if(value == -1) return binarySearch(nums,start,mid-1,target);
				else return value;
			}
			/*else if (nums[mid] < target && target > nums[end]){
				int value = binarySearch(nums,mid +1,end,target);
				if(value == -1) return binarySearch(nums,start,mid-1,target);
				else return value;
			}
			else if (nums[mid] > target && target < nums[start]){
				int value = binarySearch(nums,start,mid-1,target);
				if(value == -1) return binarySearch(nums,start,mid-1,target);
				else return value;
			}*/


		}
		else return -1;
	}


    int search(vector<int>& nums, int target) {
    	return binarySearch(nums,0,nums.size()-1,target);
		        
    }
};






int main(){

	std::vector<int> v = {0,1,2,3,4,5,6,7};
	//4 5 6 7 0 1 2
	std::vector<int> v2 = {4,5,6,7,0,1,2};


	Solution s;
	cout << s.binarySearch(v2,0,6,2);


}