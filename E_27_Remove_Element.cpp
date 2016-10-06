#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      if (!nums.size()) return 0;
      int count = 0;
        
        for(int i =0; i< nums.size();++i){
            if(nums[i] != val){
                nums[count++] = nums[i]; 
            }
        }
        return count;
        
    }
};

int main(){
	Solution s;
	std::vector<int> v = {1};
	cout << s.removeElement(v,1);
	cout << s.removeElement(v,1);
	cout << v.size();

}