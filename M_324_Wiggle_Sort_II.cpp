#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        if(n <= 1) return;

        for(int i = 1; i < n; ++i){
        	if(i % 2){
        		if(nums[i] < nums[i-1]){
        			swap(nums[i],nums[i-1]);
        			i--;
        		}
        	}else{
        		if(nums[i] > nums[i-1]){
        			swap(nums[i],nums[i-1]);
        			i--;
        		}
        	}

        }
        return;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<int> v = {1,2,3,4,5,6};
	Solution s;
	s.wiggleSort(v);

	for(int x :v){
		cout << x << " ";
	}

	return 0;
}