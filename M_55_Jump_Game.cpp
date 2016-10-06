#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
     	int size = nums.size();
     	if(size <= 1) return true;
     	int step = nums[0];
     	
     	for(int i = 1; i < size;++i){
     		//move forward 
     		step--;
     		if(step < 0) return false;
     		//break down to two steps
     		//pick the greedy options
     		if(nums[i] > step) step = nums[i];
     	}
     	return true;
    }
};

int main(int argc, char** argv){
	Solution s;
	std::vector<int> v = {3,2,1,0,4};
	cout << s.canJump(v);
}
