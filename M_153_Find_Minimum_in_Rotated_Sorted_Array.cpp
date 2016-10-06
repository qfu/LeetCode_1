#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int binarySearch(const vector<int> & nums, int l, int h){
		if(l == h) return nums[l];
		else{
			int mid  = (l + h)/2;
			int mid2 = mid +1;
			if(nums[mid] < nums[h]) return binarySearch(nums,l,mid);
			else return binarySearch(nums,mid2,h);
		}
	}


    int findMin(vector<int>& nums) {
		return findMin(nums,0,nums.size()-1);    	
    }
};


int main(int argc, char ** argv){

	vector<int> v = {6,7,2,3,4,5};
	Solution s;
	cout << s.binarySearch(v,0,v.size()-1) << endl;

}