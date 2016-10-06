#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector> 
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    	int diff = 0;
        for (auto& num : nums) {
        	// Binary version
            diff ^= num;
            cout << "num is " << num << endl;
        	cout << "diff is " << diff << endl;
        }
        cout << diff;
        return nums;
        /*
        std::vector<int> v;
        sort (nums.begin(), nums.end());

        for(int i = 0 ; i < nums.size() ; i++){
            if(i == 0){
                if(nums[i] != nums[i+1]) v.push_back(nums[i]);
            }
            else if (i == (nums.size()-1)){
                if(nums[i-1] != nums[i]) v.push_back(nums[i]);
            }
        	else if (nums[i] != nums[i-1] &&nums[i] != nums[i+1]){
        	    v.push_back(nums[i]);
        	}
        }
        return v;*/
    }
};

int main(int argc, char ** argv){
	int myints[] = {1,2,1,3,2,5};
  	std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
	Solution solver;
	vector<int> rets = {0, 0};
	solver.singleNumber(v);

}