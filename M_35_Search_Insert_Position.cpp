class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       	if(!nums.size()) return 0;
     	int index = -1;

     	for(int i = 0; i < nums.size(); ++i){
     		if(nums[i] == target) index = i;
     	}   

     	if(index != -1) return index;

     	for(int i = 0; i < nums.size(); ++i){
     		if(nums[i] > target) return i;
     	}   
     	return nums.size();
    }
};

int main(){

}