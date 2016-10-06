#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(!n) return;

        for(int i = n - 2; i >=0; --i){
        	if(nums[i+1] > nums[i]){
        		sort(nums.begin()+i+1,nums.end());
        		for(int j = i + 1; j < n;++j){
        			if(nums[j] > nums[i]){
        				swap(nums[j],nums[i]);
        				return;
        			}
        		}
        	}
        }

        reverse(nums.begin(),nums.end());
        return;
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	std::vector<int> v = {4,3,2,1};
	s.nextPermutation(v);


	for(int x : v){
		cout << x;
	}

	return 0;
}