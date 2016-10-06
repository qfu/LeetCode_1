class Solution {
public:
    void sortColors(vector<int>& nums) {
    	int key,j;
    	for(int i = 1; i < nums.size(); ++i){
    		key = nums[i];
    		j = i -1;
    		while(j >=0 && nums[j] > key){
    			nums[j+1] = nums[j];
    			j--;
    		}
    		nums[j+1] = key;
    	}
    }
};


int main(){

}