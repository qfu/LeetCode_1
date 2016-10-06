class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	set<int> set;
    	for(auto & a : nums){
    		set.insert(a);
    	}
    	return (set.size() == nums.size()) ? false: true;
        
    }
};

int main(int argc, char ** argv){


	return 0;
}