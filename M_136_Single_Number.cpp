#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {

      sort (nums.begin(), nums.end());  
      
      for(auto & ele:nums)
  	  	cout << ele << endl;   
  	  if (nums.size() == 1)
  	  	return nums[0];

      for(int i = 0; i < nums.size(); i++){
      		if (i == 0 && nums[i] != nums[i+1]){

      			return nums[0]; 
      		}

      		else if (i == (nums.size()-1) && nums[i-1] != nums[i]){

      			return nums[i];
      		}

      		else if (nums[i-1] != nums[i] && nums[i] != nums[i+1]){

      			return nums[i];
      		}
      	}
      	return 0;

    }
};

int main(int argc, char ** argv){
	 int myints[] = {17,12,5,-6,12,4,17,-5,2,-3,2,4,5,16,-3,-4,15,15,-4,-5,-6};
  	vector<int> a (myints, myints + sizeof(myints) / sizeof(int) );

	Solution solver;
	cout << solver.singleNumber(a) << endl;
}