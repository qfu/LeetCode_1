#include <vector>
#include <iostream>
#include <vector>
using namespace std;


ostream & operator<<(ostream & o, const vector<int>& v){
	for(int x : v) o << x;
	return o << endl;
}

class Solution {
private:
	int binarySearch(const vector<int>& nums, int start, int end, int target){
		
		while(start <= end){
			int mid = start + ((end - start) >> 1);
			if(nums[mid] == target) return mid+1;
			else if(nums[mid] > target) end = mid - 1;
			else start = mid+1; 
		}
		return -1;
	}
public:
    vector<int> twoSum(vector<int>& numbers, int target) {    
        int size = numbers.size();
        if(!size) return {};
        for (int i = 0; i < size; ++i){	
        	int result = binarySearch(numbers, i+1,size,target-numbers[i]);
        	if(result != -1) return {i+1,result};
        }
        return {};

	}
};

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<int> v = {0, 0, 3, 4};

	Solution s;
	cout << s.twoSum(v,0);
	return 0;
}