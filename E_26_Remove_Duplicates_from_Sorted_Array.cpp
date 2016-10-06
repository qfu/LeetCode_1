#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        for(int i =1; i< nums.size();){
            if (nums[i] == nums[i-1]){
            	//erase basically reduce i by 1;
            	//this step doesn't need to decrement
                nums.erase(nums.begin()+i-1);
            }
            else ++i;
        }
        return nums.size();
    }
};
int main(){
	std::vector<int> v ={1,1,2,2,2,3,3};
	Solution s;
	s.removeDuplicates(v);
	for_each(v.begin(),v.end(),[](int a){cout <<a;});
	return 0;
}