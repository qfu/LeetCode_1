#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = 0;
        int flag = 0;
        for(int i = 1; i < nums.size();++i){
        	if(nums[i] == nums[i-1]){
        		if (flag) s++;
        		flag = 1;
        	}
        	else{ 
        		flag = 0;
        	}
            nums[i-s] = nums[i];

        }
        return nums.size()-s;
    }
};


int main(int argc, char ** argv){

}