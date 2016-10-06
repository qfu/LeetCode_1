class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int,int> temp;
            
        for(int i = 0; i < nums.size();++i){
            if(temp.find(nums[i]) != temp.end()){
                v.push_back(i);
                v.push_back(temp[nums[i]]);
                break;
            }
            temp.insert({target - nums[i],i});
        }

        return v;
    }
};

int main(int argc, char ** argv){


	return 0;
}