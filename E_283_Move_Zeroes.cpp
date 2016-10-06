class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> copy;
        int replacement = 0;
        int length = nums.size();
        
    	for(int i =0;i < nums.size();i++){
    		if (nums[i] == 0){
    			replacement ++;
    		}else{
    		    copy.push_back(nums[i]);
    		}
    	}
    	
    	nums.erase(nums.begin(),nums.end());

    	for (int j = 0; j < length ; j++){
    	    if(j < copy.size()) nums.push_back(copy[j]);
    		else nums.push_back(0);
    	}
    }
};






int main (int argc , char ** argv ){

}